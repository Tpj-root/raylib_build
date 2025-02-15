#include "raylib.h"

int main() {
    InitWindow(800, 600, "DrawSphereWires Example");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 6.0f, 6.0f, 12.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Look at the sphere
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Define sphere parameters
        Vector3 spherePosition = { 0.0f, 0.0f, 0.0f };
        float sphereRadius = 2.0f;
        int rings = 16;   // More rings = smoother sphere
        int slices = 16;  // More slices = smoother sphere

        // Draw the sphere wireframe
        DrawSphereWires(spherePosition, sphereRadius, rings, slices, BLUE);

        EndMode3D();

        DrawText("3D Sphere Wireframe Example (DrawSphereWires)", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

