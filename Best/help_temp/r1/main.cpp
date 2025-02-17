#include "RubiksCube.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Rubik's Cube");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 30.0f, 30.0f, 30.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    RubiksCube cube;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_A)) {
            cube.RotateFront(true); // Rotate front face clockwise
        }
        if (IsKeyPressed(KEY_S)) {
            cube.RotateBack(true); // Rotate back face clockwise
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        cube.Draw();
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}