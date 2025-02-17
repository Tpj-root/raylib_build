#include "raylib.h"

int main(void)
{
    // Initialize window
    const int screenWidth = 1200;
    const int screenHeight = 750;
    InitWindow(screenWidth, screenHeight, "Raylib Background Example");

    // Load background image
    Texture2D background = LoadTexture("3d_background.png"); // Make sure to have background.png in the same folder

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main game loop
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //
        DrawTextureEx(background, (Vector2){0, 0}, 0.0f, (float)screenWidth / background.width, WHITE);

        // Draw background image
        //DrawTexture(background, 0, 0, WHITE);

        DrawText("Welcome to Raylib!", 250, 50, 20, DARKBLUE);

        EndDrawing();
    }

    // Unload resources
    UnloadTexture(background);
    CloseWindow();

    return 0;
}
