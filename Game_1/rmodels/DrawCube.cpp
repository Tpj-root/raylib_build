#include "raylib.h"

int main() {
    InitWindow(800, 600, "Draw Cube 3D");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };  // Set camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Look at the cube
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCube((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, RED);  // Draw cube at (0,0,0)
        DrawCubeWires((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BLACK);  // Draw cube edges

        EndMode3D();

        DrawText("3D Cube Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
