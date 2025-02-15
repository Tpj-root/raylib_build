#include "raylib.h"

int main() {
    InitWindow(800, 600, "DrawCylinderWires Example");

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
        Vector3 position = { 0.0f, 0.0f, 0.0f }; // Cylinder center
        float radiusTop = 1.0f;  // Top radius
        float radiusBottom = 1.5f; // Bottom radius
        float height = 4.0f;  // Cylinder height
        int slices = 16;      // Number of sides for smoothness

        // Draw the cylinder wireframe
        DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, RED);

        EndMode3D();

        DrawText("3D Cylinder Wireframe Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

