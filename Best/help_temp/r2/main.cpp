#include "Cube.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "3x3x3 Rubik's Cube");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Cube cube;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Handle input
        if (IsKeyPressed(KEY_F)) cube.RotateFace(0, true);  // Rotate front face clockwise
        if (IsKeyPressed(KEY_B)) cube.RotateFace(1, true);  // Rotate back face clockwise
        if (IsKeyPressed(KEY_L)) cube.RotateFace(2, true);  // Rotate left face clockwise
        if (IsKeyPressed(KEY_R)) cube.RotateFace(3, true);  // Rotate right face clockwise
        if (IsKeyPressed(KEY_U)) cube.RotateFace(4, true);  // Rotate up face clockwise
        if (IsKeyPressed(KEY_D)) cube.RotateFace(5, true);  // Rotate down face clockwise
        if (IsKeyPressed(KEY_S)) cube.Shuffle();            // Shuffle the cube

        // Update camera
        UpdateCamera(&camera, CAMERA_ORBITAL);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        cube.Draw();
        EndMode3D();

        DrawText("Use F, B, L, R, U, D to rotate faces", 10, 10, 20, BLACK);
        DrawText("Press S to shuffle the cube", 10, 40, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}