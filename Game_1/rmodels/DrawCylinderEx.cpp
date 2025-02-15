#include "raylib.h"

int main() {
    InitWindow(800, 600, "DrawCylinderEx Example");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 6.0f, 6.0f, 12.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Look at the cylinder
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Define cylinder parameters
        Vector3 startPos = { 0.0f, -2.0f, 0.0f }; // Bottom center
        Vector3 endPos = { 0.0f, 2.0f, 0.0f };   // Top center
        float startRadius = 1.5f;  // Bottom radius
        float endRadius = 1.0f;    // Top radius
        int sides = 16;            // Number of sides for smoothness

        // Draw the cylinder
        DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, BLUE);

        EndMode3D();

        DrawText("3D Cylinder Example (DrawCylinderEx)", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

