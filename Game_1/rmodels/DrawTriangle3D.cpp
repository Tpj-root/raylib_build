#include "raylib.h"

int main() {
    InitWindow(800, 600, "Draw Triangle 3D");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawTriangle3D(
            (Vector3){ -2.0f, 0.0f, 0.0f },  // First vertex
            (Vector3){ 2.0f, 0.0f, 0.0f },   // Second vertex
            (Vector3){ 0.0f, 3.0f, 0.0f },   // Third vertex (top)
            RED
        );
        EndMode3D();

        DrawText("3D Triangle Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
