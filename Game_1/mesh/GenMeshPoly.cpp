#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "GenMeshPoly Example");

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 5.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Mesh mesh = GenMeshPoly(6, 1.0f);  // Generate a hexagon (6-sided polygon)
    Model model = LoadModelFromMesh(mesh);

    while (!WindowShouldClose()) {
        // Update
        UpdateCamera(&camera, CAMERA_ORBITAL);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginMode3D(camera);
        DrawModel(model, (Vector3){ 0, 0, 0 }, 1.0f, RED);
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawText("Polygon Mesh Example", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // Cleanup
    UnloadModel(model);
    CloseWindow();

    return 0;
}

