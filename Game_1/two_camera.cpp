#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib - Small Camera View");

    // Main Camera (Big View)
    Camera3D cameraMain = { 0 };
    cameraMain.position = (Vector3){ 5.0f, 5.0f, 5.0f };
    cameraMain.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    cameraMain.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cameraMain.fovy = 45.0f;
    cameraMain.projection = CAMERA_PERSPECTIVE;

    // Small Camera (Mini Viewport)
    Camera3D cameraMini = { 0 };
    cameraMini.position = (Vector3){ -5.0f, 5.0f, 5.0f };
    cameraMini.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    cameraMini.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cameraMini.fovy = 45.0f;
    cameraMini.projection = CAMERA_PERSPECTIVE;

    // Render texture for mini camera
    RenderTexture2D miniView = LoadRenderTexture(200, 150); // Small size

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Render small camera view to texture
        BeginTextureMode(miniView);
            ClearBackground(SKYBLUE);
            BeginMode3D(cameraMini);
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, BLUE);
                DrawGrid(10, 1.0f);
            EndMode3D();
        EndTextureMode();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Main Camera (Full Screen)
        BeginMode3D(cameraMain);
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            DrawGrid(10, 1.0f);
        EndMode3D();

        // Draw Mini Camera View at Bottom Right
        DrawTextureRec(miniView.texture, (Rectangle){ 0, 0, 200, -150 }, (Vector2){ screenWidth - 210, screenHeight - 160 }, WHITE);

        // UI Text
        DrawText("Mini Camera View", screenWidth - 210, screenHeight - 180, 10, BLACK);

        EndDrawing();
    }

    UnloadRenderTexture(miniView);
    CloseWindow();
    return 0;
}
