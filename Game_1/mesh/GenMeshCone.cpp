#include "raylib.h"

int main() {
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "GenMeshCone Example");

    // Camera setup
    Camera camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 5.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };   // Looking at the cone
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };       // Up direction
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Generate cone mesh and load model
    Mesh mesh = GenMeshCone(2.0f, 4.0f, 32); // Radius 2.0, Height 4.0, 32 slices
    Model model = LoadModelFromMesh(mesh);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update camera
        UpdateCamera(&camera, CAMERA_ORBITAL);

        // Render
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawModel(model, (Vector3){ 0, 0, 0 }, 1.0f, BLUE); // Draw the cone
        DrawGrid(10, 1.0f); // Reference grid
        EndMode3D();

        DrawText("GenMeshCone Example", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // Cleanup
    UnloadModel(model);
    CloseWindow();

    return 0;
}

