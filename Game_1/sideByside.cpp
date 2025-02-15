#include "raylib.h"

// Function to create a camera
Camera3D CreateCamera(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection) {
    Camera3D camera = { 0 };
    camera.position = position;
    camera.target = target;
    camera.up = up;
    camera.fovy = fovy;
    camera.projection = projection;
    return camera;
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3D camera free");

    Camera3D topView = CreateCamera((Vector3){ 0.0f, 5.0f, 0.0f }, 
                                     (Vector3){ 0.0f, 0.0f, 0.0f }, 
                                     (Vector3){ 1.0f, 0.0f, 0.0f }, 
                                     45.0f, CAMERA_PERSPECTIVE);
     
    Camera3D downView = CreateCamera((Vector3){ 0.0f, -5.0f, 0.0f }, 
                                      (Vector3){ 0.0f, 0.0f, 0.0f }, 
                                      (Vector3){ 1.0f, 0.0f, 0.0f }, 
                                      45.0f, CAMERA_PERSPECTIVE);
     
    int activeCamera = 2; // 1 = topView, 2 = downView

    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE)) activeCamera = (activeCamera == 1) ? 2 : 1;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            BeginMode3D(activeCamera == 1 ? topView : downView);
                DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, RED);
                DrawGrid(10, 1.0f);
            EndMode3D();

            DrawRectangle(10, 10, 300, 100, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(10, 10, 300, 100, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
