#include <stdio.h>

#define MAZ_SIZE 100

typedef struct {
    int elements[MAZ_SIZE];
    int size;
} Set;

void initSet(Set* s) {
    s->size = 0;
}

bool addElement(Set* s, int element) {
    if (s-> size >= MAZ_SIZE) return false;
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    s->elements[s->size++] = element;
    return true;
}

bool isEmpty(Set* s) {
    return s->size == 0;
}

bool isMember(Set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) return true;
    }
    return false;
}

bool isEqual(Set* s1, Set* s2) {
    if (s1->size != s2->size) return false;
    for (int i = 0; i < s1->size; i++) {
        if (!isMember(s1, s2->elements[i])) return false;
    }
    return true;
}

bool isSubSet(Set* s1, Set* s2) {
    if (s1->size > s2->size) return false;
    for (int i = 0; i < s1->size; i++) {
        if (!isMember(s2, s1->elements[i])) return false;
    }
    return true;
}

Set unionSet(Set* s1, Set* s2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < s1->size; i++) {
        addElement(&result, s1->elements[i]);
    }
    for (int i = 0; i < s2->size; i++) {
        addElement(&result, s2->elements[i]);
    }
    return result;
}

Set intersectionSet(Set* s1, Set* s2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < s1->size; i++) {
        if (isMember(s2, s1->elements[i])) {
            addElement(&result, s1->elements[i]);
        }
    }
    return result;
}

Set differenceSet(Set* s1, Set* s2) {
    Set result;
    initSet(&result);
    for (int i = 0; i < s1->size; i++) {
        if (!isMember(s2, s1->elements[i])) {
            addElement(&result, s1->elements[i]);
        }
    }
    return result;
}

int main() {
    Set A, B, C;
    initSet(&A);
    initSet(&B);
    initSet(&C);
    for (int i = 0; i < 10; i++) {
        addElement(&A, i);
        addElement(&B, i);
    }
    for (int i = 0; i < 5; i++) {
        addElement(&C, i);  // Sửa từ B thành C để tạo sự khác biệt giữa các tập
    }
    printf("A equals B: %s\n", isEqual(&A, &B) ? "true" : "false");
    printf("C is subset of A: %s\n", isSubSet(&C, &A) ? "true" : "false");
    Set D = differenceSet(&A, &C);
    printf("Elements in A - C: ");
    for (int i = 0; i < D.size; i++) {
        printf("%d ", D.elements[i]);
    }
    printf("\n");
    return 0;
}