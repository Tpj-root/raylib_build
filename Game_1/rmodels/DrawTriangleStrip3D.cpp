#include "raylib.h"

int main() {
    InitWindow(800, 600, "Triangle Strip 3D");
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 6.0f };  
    camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };    
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 points[] = {
        { -1.0f, 0.0f,  1.0f },
        {  0.0f, 1.0f,  1.0f },
        {  1.0f, 0.0f,  1.0f },
        {  1.0f, 1.0f, -1.0f },
        { -1.0f, 0.0f, -1.0f }
    };
    int pointCount = sizeof(points) / sizeof(points[0]);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        
        DrawTriangleStrip3D(points, pointCount, RED);
        
        EndMode3D();
        DrawText("Triangle Strip 3D", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
