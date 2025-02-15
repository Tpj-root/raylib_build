#include "raylib.h"
#include <stdio.h>

#define PI 3.141


// #ifndef PI
//     #define PI 3.14159265358979323846f
// #endif
// #ifndef DEG2RAD
//     #define DEG2RAD (PI / 180.0f)
// #endif
// #ifndef RAD2DEG
//     #define RAD2DEG (180.0f / PI)
// #endif


int main() {
    Vector2 position = {400.0f, 300}; // Define a Vector2
    Vector3 v3 = {1, 2.0f, 3.0f};     // 3D vector
    Vector4 v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // 4D vector

    printf("Vector2 Position: x = %.2f, y = %.2f\n", position.x, position.y);
    printf("Vector3: x = %.2f, y = %.2f, z = %.2f\n", v3.x, v3.y, v3.z);
    printf("Vector4: x = %.2f, y = %.2f, z = %.2f, w = %.2f\n", v4.x, v4.y, v4.z, v4.w);


    float degrees = 90.0f;
    float radians = degrees * DEG2RAD;  // Convert 90° to radians
    float backToDegrees = radians * RAD2DEG;  // Convert back to degrees

    printf("Degrees: %.6f\n", PI);
    printf("Degrees: %.2f\n", degrees);
    printf("Radians: %.6f\n", radians);
    printf("Back to Degrees: %.2f\n", backToDegrees);

    return 0;
}