#include "raylib.h"

int main() {
    InitWindow(800, 600, "DrawPlane Example");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };       // Looking at the plane
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Define plane parameters
        Vector3 centerPos = { 0.0f, 0.0f, 0.0f };  // Plane center position
        Vector2 size = { 10.0f, 10.0f };           // Plane size (width & length)

        // Draw the plane on the XZ axis
        DrawPlane(centerPos, size, LIGHTGRAY);

        EndMode3D();

        DrawText("3D Plane Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

