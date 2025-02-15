#include "raylib.h"

int main() {
    InitWindow(800, 600, "Draw CubeV 3D");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Look at cube
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    Vector3 cubeSize = { 2.0f, 2.0f, 2.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCubeV(cubePosition, cubeSize, BLUE);   // Draw blue cube
        DrawCubeWiresV(cubePosition, cubeSize, BLACK); // Draw cube edges

        EndMode3D();

        DrawText("3D CubeV Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
