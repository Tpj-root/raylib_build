#include "raylib.h"

int main() {
    InitWindow(800, 600, "DrawCylinderWiresEx Example");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 8.0f, 8.0f, 12.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Looking at the cylinder
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Define cylinder parameters
        Vector3 startPos = { -2.0f, -2.0f, 0.0f };  // Cylinder base position
        Vector3 endPos = { 2.0f, 2.0f, 0.0f };      // Cylinder top position
        float startRadius = 1.0f;  // Base radius
        float endRadius = 0.5f;    // Top radius
        int sides = 16;            // Number of sides for smoothness

        // Draw the cylinder wireframe from startPos to endPos
        DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, BLUE);

        EndMode3D();

        DrawText("3D Cylinder Wires Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

