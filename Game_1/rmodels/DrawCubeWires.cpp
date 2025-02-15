#include "raylib.h"

int main() {
    InitWindow(800, 600, "Draw Cube Wires");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Look at the cube
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Draw a wireframe cube at (0,0,0) with width=2, height=2, length=2, color BLACK
        DrawCubeWires((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BLACK);

        EndMode3D();

        DrawText("3D Cube Wireframe Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

