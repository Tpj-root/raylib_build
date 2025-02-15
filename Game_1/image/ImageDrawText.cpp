#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "ImageDrawText Example");

    // Create an empty image
    Image img = GenImageColor(400, 300, RAYWHITE); // White background

    // Draw text onto the image
    ImageDrawText(&img, "Hello, Raylib!", 50, 150, 30, RED);

    // Convert image to texture for rendering
    Texture2D texture = LoadTextureFromImage(img);
    UnloadImage(img);  // Free image memory (not needed after loading into texture)

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(texture, 200, 150, WHITE); // Draw image with text on screen

        EndDrawing();
    }

    // Cleanup
    UnloadTexture(texture);
    CloseWindow();

    return 0;
}

