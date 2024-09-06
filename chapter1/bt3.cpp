#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
    float radius;
} Sphere;

Sphere createSphere(float x, float y, float z, float radius) {
    Sphere sphere{x, y, z, radius};
    return sphere;
}

float surfaceArea(Sphere sphere) {
    return 4 * M_PI * sphere.radius * sphere.radius;
}

float volume(Sphere sphere) {
    return (4.0f / 3.0f) * M_PI * sphere.radius * sphere.radius * sphere.radius;
}

bool isInside(Sphere sphere, float x, float y, float z) {
    float dx = sphere.x - x;
    float dy = sphere.y - y;
    float dz = sphere.z - z;
    float distance = sqrt(dx * dx + dy * dy + dz * dz);
    return sphere.radius > distance;
}

Sphere translate(Sphere sphere, float x, float y, float z) {
    sphere.x += x;
    sphere.y += y;
    sphere.z += z;
    return createSphere(sphere.radius, sphere.x, sphere.y, sphere.z);
}

float distanceBetweenSpheres(Sphere s1, Sphere s2) {
    float dx = s1.x - s2.x;
    float dy = s1.y - s2.y;
    float dz = s1.z - s2.z;
    float distance = sqrt(dx * dx + dy * dy + dz * dz) - s1.radius - s2.radius;
    return distance > 0 ? distance : 0;
}

int main() {
    // Example usage
    Sphere sphere = createSphere(0, 0, 0, 2.0f);
    printf("Surface area: %.2f\n", surfaceArea(sphere));
    printf("Volume: %.2f\n", volume(sphere));
    return 0;
}
