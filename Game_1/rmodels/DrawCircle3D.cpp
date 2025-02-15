#include "raylib.h"

int main() {
    InitWindow(800, 600, "Draw Circle 3D");

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
        DrawCircle3D((Vector3){ 0, 0, 0 }, 3.0f, (Vector3){ 1, 0, 0 }, 90.0f, RED);  // Draw a red circle in the X-Z plane
        EndMode3D();

        DrawText("3D Circle Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
