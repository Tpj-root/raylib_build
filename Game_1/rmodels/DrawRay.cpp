#include "raylib.h"

int main() {
    InitWindow(800, 600, "Raylib - Draw Ray");
    
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Ray ray = { (Vector3){ 0, 2, 0 }, (Vector3){ 1, -1, 1 } }; // Origin at (0,2,0) and direction (1,-1,1)

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginMode3D(camera);
        
        DrawRay(ray, RED);  // Draw the ray in RED
        DrawGrid(10, 1.0f); // Grid for reference

        EndMode3D();
        
        DrawText("Ray drawn in 3D space", 10, 10, 20, DARKGRAY);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

