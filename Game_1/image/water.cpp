#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 1200;
    const int screenHeight = 627;
    InitWindow(screenWidth, screenHeight, "Watermark Example");
    // Load an image (Replace with your own image path)
    Image image = LoadImage("1.jpg");

    // Draw watermark text on the image (Bottom-right corner)
    int fontSize = 200;
    int textX = image.width - MeasureText("Watermark", fontSize) - 10; // Align right
    int textY = image.height - fontSize - 10; // Align bottom
    ImageDrawText(&image, "Watermark", textX, textY, fontSize, Fade(BLACK, 0.5f)); // 50% transparency

    // Convert image to texture for rendering
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);  // Free image memory

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(texture, 100, 100, WHITE); // Display the image with the watermark

        EndDrawing();
    }

    // Cleanup
    UnloadTexture(texture);
    CloseWindow();

    return 0;
}

