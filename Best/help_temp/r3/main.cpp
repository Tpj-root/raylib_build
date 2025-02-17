#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Simple 3D Cube Rotation");

    // Define the camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Camera target
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };         // Camera up vector
    camera.fovy = 45.0f;                               // Camera field-of-view
    camera.projection = CAMERA_PERSPECTIVE;            // Camera projection type

    // Cube rotation variables
    float rotationAngle = 0.0f; // Current rotation angle
    bool rotateCW = false;      // Flag for clockwise rotation
    bool rotateCCW = false;     // Flag for counter-clockwise rotation

    SetTargetFPS(60); // Set the target frames-per-second

    // Main game loop
    while (!WindowShouldClose()) {
        // Handle input
        if (IsKeyPressed(KEY_A)) {
            rotateCW = true;  // Rotate clockwise
        }
        if (IsKeyPressed(KEY_S)) {
            rotateCCW = true; // Rotate counter-clockwise
        }

        // Update rotation
        if (rotateCW) {
            rotationAngle += 90.0f; // Rotate 90 degrees CW
            rotateCW = false;       // Reset flag
        }
        if (rotateCCW) {
            rotationAngle -= 90.0f; // Rotate 90 degrees CCW
            rotateCCW = false;      // Reset flag
        }

        // Begin drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Begin 3D mode
        BeginMode3D(camera);

        // Draw the cube
        DrawCube((Vector3){ 2.0f, 2.0f, 2.0f }, 2.0f, 2.0f, 2.0f, RED); // Cube
        DrawCubeWires((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BLACK); // Cube wires

        // Apply rotation
        DrawCubeWires((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BLACK); // Draw cube wires
        DrawGrid(10, 1.0f); // Draw a grid for reference

        // End 3D mode
        EndMode3D();

        // Draw instructions
        DrawText("Press A to rotate CW, S to rotate CCW", 10, 10, 20, BLACK);

        // End drawing
        EndDrawing();
    }

    // Close the window
    CloseWindow();
    return 0;
}