#include "raylib.h"

// Custom function to clamp a value between a minimum and maximum
float Clamp(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "3D Room View");

    // Load textures for the walls
    Texture2D images[4];
    images[0] = LoadTexture("1.png");
    images[1] = LoadTexture("2.png");
    images[2] = LoadTexture("3.png");
    images[3] = LoadTexture("4.png");

    // Set up camera
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 1.8f, 3.0f };  // Initial camera position (looking into the room)
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };    // Camera is looking towards the center of the room
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;   // Field of view
    camera.projection = CAMERA_PERSPECTIVE;

    // Set zoom and speed variables
    float zoom = 1.0f;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        UpdateCamera(&camera, CAMERA_FREE);

        // Mouse control for zoom
        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
            zoom += wheel * 0.1f;
            zoom = Clamp(zoom, 0.1f, 2.0f);  // Clamp zoom to a reasonable range
            camera.fovy = 45.0f / zoom;     // Adjust FOV for zoom effect
        }

        // Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Front wall
        DrawCube((Vector3){ 0.0f, 1.8f, -5.0f }, 10.0f, 4.0f, 0.2f, RED);
        DrawCubeWires((Vector3){ 0.0f, 1.8f, -5.0f }, 10.0f, 4.0f, 0.2f, BLACK);

        // Back wall
        DrawCube((Vector3){ 0.0f, 1.8f, 5.0f }, 10.0f, 4.0f, 0.2f, WHITE);
        DrawCubeWires((Vector3){ 0.0f, 1.8f, 5.0f }, 10.0f, 4.0f, 0.2f, BLACK);

        // Left wall
        DrawCube((Vector3){ -5.0f, 1.8f, 0.0f }, 0.2f, 4.0f, 10.0f, WHITE);
        DrawCubeWires((Vector3){ -5.0f, 1.8f, 0.0f }, 0.2f, 4.0f, 10.0f, BLACK);

        // Right wall
        DrawCube((Vector3){ 5.0f, 1.8f, 0.0f }, 0.2f, 4.0f, 10.0f, WHITE);
        DrawCubeWires((Vector3){ 5.0f, 1.8f, 0.0f }, 0.2f, 4.0f, 10.0f, BLACK);

        EndMode3D();

        DrawText("Use WASD to move the camera, and Mouse Wheel to Zoom In/Out", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    // De-Initialization
    for (int i = 0; i < 4; i++) {
        UnloadTexture(images[i]);  // Unload textures
    }

    CloseWindow();  // Close window and OpenGL context

    return 0;
}