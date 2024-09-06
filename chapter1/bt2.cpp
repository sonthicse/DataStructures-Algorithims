#include <stdio.h>
#include <math.h>
#define O createPoint(0, 0) 

typedef struct {
    float x;
    float y;
} Point;

Point createPoint(float x, float y) {
    Point point{x, y};
    return point;
}

Point translate(Point point, float dx, float dy) {
    point.x += dx;
    point.y += dy;
    return point;
}

Point rotate(Point point, float angle, Point center) {
    float newX = center.x + (point.x - center.x) * cos(angle) - (point.y - center.y) * sin(angle);
    float newY = center.y + (point.x - center.x) * sin(angle) + (point.y - center.y) * cos(angle);
    return createPoint(newX, newY);
}

float distance(Point x, Point y) {
    float dx = x.x - y.x;
    float dy = x.y - y.y;
    float distance = sqrt(pow(dx, 2) + pow(dy, 2));
    return distance;
}

Point midpoint(Point x, Point y) {
    float newX = (x.x + y.x) / 2;
    float newY = (x.y + y.y) / 2;
    return createPoint(newX, newY);
}

int main() {

    Point p1 = createPoint(1, 1);
    Point p2 = createPoint(4, 5);
    
    Point p3 = translate(p1, 2, 2);
    Point p4 = rotate(p1, M_PI/4, O);  // Quay 45 độ
    double dist = distance(p1, p2);
    Point mid = midpoint(p1, p2);
    
    printf("Translated point: (%.2f, %.2f)\n", p3.x, p3.y);
    printf("Rotated point: (%.2f, %.2f)\n", p4.x, p4.y);
    printf("Distance between points: %.2f\n", dist);
    printf("Midpoint: (%.2f, %.2f)\n", mid.x, mid.y);

    return 0;
}