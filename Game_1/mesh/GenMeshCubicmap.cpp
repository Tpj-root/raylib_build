#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "GenMeshCubicmap Example");

    // Load the cubicmap image (black & white PNG)
    Image cubicmap = LoadImage("D.png");  
    Texture2D cubicmapTexture = LoadTextureFromImage(cubicmap); 

    // Convert image to cubic map mesh
    Mesh mesh = GenMeshCubicmap(cubicmap, (Vector3){ 1.0f, 1.0f, 1.0f });
    Model model = LoadModelFromMesh(mesh);

    // Define camera
    Camera camera = { 0 };
    camera.position = (Vector3){ 8.0f, 8.0f, 8.0f };  
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };    
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };        
    camera.fovy = 45.0f;                             
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawModel(model, (Vector3){ -cubicmap.width / 2, 0, -cubicmap.height / 2 }, 1.0f, WHITE);
        EndMode3D();

        DrawTextureEx(cubicmapTexture, (Vector2){ 10, 10 }, 0, 4.0f, RED);
        DrawFPS(10, 50);
        EndDrawing();
    }

    // Cleanup
    UnloadTexture(cubicmapTexture);
    UnloadImage(cubicmap);
    UnloadModel(model);
    CloseWindow();

    return 0;
}

