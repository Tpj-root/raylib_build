#include "raylib.h"

int main() {
    InitWindow(800, 600, "Draw Sphere Example");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Look at the sphere
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Define sphere position and radius
        Vector3 spherePosition = { 0.0f, 0.0f, 0.0f };
        float sphereRadius = 2.0f;

        // Draw the sphere
        DrawSphere(spherePosition, sphereRadius, BLUE);

        EndMode3D();

        DrawText("3D Sphere Example (DrawSphere)", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

