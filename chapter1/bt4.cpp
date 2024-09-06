#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
#define EPSILON 1e-10

typedef struct {
    int row;
    int col;
    double matrix[MAX_SIZE][MAX_SIZE];
} Matrix;

// Hàm tạo ma trận
Matrix createMatrix(int row, int col) {
    Matrix matrix = {row, col};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix.matrix[i][j] = 0;
        }
    }
    return matrix;
}

// Hàm lấy phần tử
double getElement(Matrix matrix, int i, int j) {
    return matrix.matrix[i - 1][j - 1];
}

// Hàm đặt giá trị cho phần tử
void setElement(Matrix* matrix, int i, int j, double value) {
    matrix->matrix[i - 1][j - 1] = value;
}

// Hàm cộng ma trận
Matrix addMatrix(Matrix matrix1, Matrix matrix2) {
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        exit(1);
    }
    Matrix result = createMatrix(matrix1.row, matrix1.col);
    for (int i = 0; i < result.row; i++) {
        for (int j = 0; j < result.col; j++) {
            result.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
        }
    }
    return result;
}

// Hàm nhân ma trận với một số
Matrix scalarMultiply(Matrix matrix, double value) {
    Matrix result = createMatrix(matrix.row, matrix.col);
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            result.matrix[i][j] = matrix.matrix[i][j] * value;
        }
    }
    return result;
}

// Hàm nhân ma trận
Matrix multiplyMatrix(Matrix matrix1, Matrix matrix2) {
    if (matrix1.col != matrix2.row) {
        printf("Error: Number of columns in first matrix must equal number of rows in second matrix.\n");
        exit(1);
    }
    Matrix result = createMatrix(matrix1.row, matrix2.col);
    for (int i = 0; i < matrix1.row; i++) {
        for (int j = 0; j < matrix2.col; j++) {
            for (int k = 0; k < matrix1.col; k++) {
                result.matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
            }
        }
    }
    return result;
}

// Hàm chuyển vị ma trận
Matrix transposeMatrix(Matrix matrix) {
    Matrix result = createMatrix(matrix.col, matrix.row);
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            result.matrix[j][i] = matrix.matrix[i][j];
        }
    }
    return result;
}

// Hàm tính định thức (sử dụng phương pháp khai triển Laplace)
double determinant(Matrix matrix) {
    if (matrix.row != matrix.col) {
        printf("Error: Matrix must be square to calculate determinant.\n");
        exit(1);
    }
    if (matrix.row == 1) {
        return matrix.matrix[0][0];
    }
    if (matrix.row == 2) {
        return matrix.matrix[0][0] * matrix.matrix[1][1] - matrix.matrix[0][1] * matrix.matrix[1][0];
    }
    double det = 0;
    for (int j = 0; j < matrix.col; j++) {
        Matrix submatrix = createMatrix(matrix.row - 1, matrix.col - 1);
        for (int i = 1; i < matrix.row; i++) {
            int k = 0;
            for (int l = 0; l < matrix.col; l++) {
                if (l != j) {
                    submatrix.matrix[i-1][k] = matrix.matrix[i][l];
                    k++;
                }
            }
        }
        det += (j % 2 == 0 ? 1 : -1) * matrix.matrix[0][j] * determinant(submatrix);
    }
    return det;
}

// Hàm tính ma trận phụ hợp
Matrix adjointMatrix(Matrix matrix) {
    Matrix adj = createMatrix(matrix.row, matrix.col);
    if (matrix.row == 1) {
        adj.matrix[0][0] = 1;
        return adj;
    }
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            Matrix submatrix = createMatrix(matrix.row - 1, matrix.col - 1);
            int r = 0, c = 0;
            for (int row = 0; row < matrix.row; row++) {
                for (int col = 0; col < matrix.col; col++) {
                    if (row != i && col != j) {
                        submatrix.matrix[r][c++] = matrix.matrix[row][col];
                        if (c == matrix.col - 1) {
                            r++;
                            c = 0;
                        }
                    }
                }
            }
            adj.matrix[j][i] = ((i+j) % 2 == 0 ? 1 : -1) * determinant(submatrix);
        }
    }
    return adj;
}

// Hàm tính ma trận nghịch đảo
Matrix inverseMatrix(Matrix matrix) {
    double det = determinant(matrix);
    if (fabs(det) < EPSILON) {
        printf("Error: Matrix is not invertible.\n");
        exit(1);
    }
    Matrix adj = adjointMatrix(matrix);
    return scalarMultiply(adj, 1.0 / det);
}

// Hàm tính hạng của ma trận (sử dụng phương pháp khử Gauss)
int rank(Matrix matrix) {
    int rank = 0;
    int rowCount = matrix.row;
    int colCount = matrix.col;
    int lead = 0;
    Matrix temp = matrix;

    while (lead < rowCount) {
        int i, j;
        for (i = 0; i < rowCount; i++) {
            double d = temp.matrix[i][lead];
            for (j = 0; j < colCount; j++) {
                temp.matrix[i][j] -= d * temp.matrix[lead][j];
            }
        }
        lead++;
    }

    for (int i = 0; i < rowCount; i++) {
        int nonZero = 0;
        for (int j = 0; j < colCount; j++) {
            if (fabs(temp.matrix[i][j]) > EPSILON) {
                nonZero = 1;
                break;
            }
        }
        if (nonZero) {
            rank++;
        }
    }

    return rank;
}

// Hàm kiểm tra ma trận đơn vị
int isIdentity(Matrix matrix) {
    if (matrix.row != matrix.col) {
        return 0;
    }
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            if (i == j && fabs(matrix.matrix[i][j] - 1) > EPSILON) {
                return 0;
            }
            if (i != j && fabs(matrix.matrix[i][j]) > EPSILON) {
                return 0;
            }
        }
    }
    return 1;
}

// Hàm trích xuất ma trận con
Matrix subMatrix(Matrix matrix, int startRow, int startCol, int endRow, int endCol) {
    if (startRow < 1 || startCol < 1 || endRow > matrix.row || endCol > matrix.col || startRow > endRow || startCol > endCol) {
        printf("Error: Invalid submatrix dimensions.\n");
        exit(1);
    }
    Matrix sub = createMatrix(endRow - startRow + 1, endCol - startCol + 1);
    for (int i = startRow - 1; i < endRow; i++) {
        for (int j = startCol - 1; j < endCol; j++) {
            sub.matrix[i - startRow + 1][j - startCol + 1] = matrix.matrix[i][j];
        }
    }
    return sub;
}

// Hàm giải hệ phương trình tuyến tính (Ax = b)
Matrix solveLinearSystem(Matrix A, Matrix b) {
    if (A.row != A.col || A.row != b.row || b.col != 1) {
        printf("Error: Invalid dimensions for solving linear system.\n");
        exit(1);
    }
    double det = determinant(A);
    if (fabs(det) < EPSILON) {
        printf("Error: System has no unique solution (matrix A is singular).\n");
        exit(1);
    }
    Matrix inv = inverseMatrix(A);
    return multiplyMatrix(inv, b);
}

// Hàm in ma trận
void printMatrix(Matrix matrix) {
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            printf("%f ", matrix.matrix[i][j]);
        }
        printf("\n");
    }
}

// Hàm main để kiểm tra các hàm
int main() {
    // Tạo ma trận A
    Matrix A = createMatrix(3, 3);
    setElement(&A, 1, 1, 1); setElement(&A, 1, 2, 2); setElement(&A, 1, 3, 3);
    setElement(&A, 2, 1, 4); setElement(&A, 2, 2, 5); setElement(&A, 2, 3, 6);
    setElement(&A, 3, 1, 7); setElement(&A, 3, 2, 8); setElement(&A, 3, 3, 9);

    // Tạo ma trận B
    Matrix B = createMatrix(3, 3);
    setElement(&B, 1, 1, 9); setElement(&B, 1, 2, 8); setElement(&B, 1, 3, 7);
    setElement(&B, 2, 1, 6); setElement(&B, 2, 2, 5); setElement(&B, 2, 3, 4);
    setElement(&B, 3, 1, 3); setElement(&B, 3, 2, 2); setElement(&B, 3, 3, 1);

    // Kiểm tra các phép toán
    printf("Matrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    printf("\nA + B:\n");
    printMatrix(addMatrix(A, B));

    printf("\nA * 2:\n");
    printMatrix(scalarMultiply(A, 2));

    printf("\nA * B:\n");
    printMatrix(multiplyMatrix(A, B));

    printf("\nTranspose of A:\n");
    printMatrix(transposeMatrix(A));

    printf("\nDeterminant of A: %f\n", determinant(A));

    printf("\nInverse of B:\n");
    printMatrix(inverseMatrix(B));

    printf("\nRank of A: %d\n", rank(A));

    printf("\nIs A identity matrix? %s\n", isIdentity(A) ? "Yes" : "No");

    printf("\nSubmatrix of A (2,2 to 3,3):\n");
    printMatrix(subMatrix(A, 2, 2, 3, 3));

    // Giải hệ phương trình Ax = b
    Matrix b = createMatrix(3, 1);
    setElement(&b, 1, 1, 1);
    setElement(&b, 2, 1, 2);
    setElement(&b, 3, 1, 3);

    printf("\nSolve Ax = b:\n");
    printf("A:\n");
    printMatrix(A);
    printf("b:\n");
    printMatrix(b);
    printf("x:\n");
    printMatrix(solveLinearSystem(A, b));

    return 0;
}