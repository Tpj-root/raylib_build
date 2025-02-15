#include "raylib.h"

//https://www.ultraengine.com/community/topic/7196-terrain-texture-with-blend-pattern-in-alpha/

int main() {
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "GenMeshHeightmap Example");

    // Load heightmap image (must be grayscale)
    Image heightmap = LoadImage("Heightmap.png"); 
    //Image heightmap = LoadImage("c.png"); 
    Texture2D heightmapTexture = LoadTextureFromImage(heightmap); // To visualize heightmap
    
    // Generate mesh from heightmap
    Vector3 mapSize = { 16.0f, 4.0f, 16.0f };  // Width, Height, Depth scaling
    Mesh mesh = GenMeshHeightmap(heightmap, mapSize);
    Model model = LoadModelFromMesh(mesh);

    // Set model texture
    Texture2D texture = LoadTexture("alphablend.png"); 
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    // Unload heightmap after creating mesh
    UnloadImage(heightmap);

    // Camera setup
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 6.0f, 10.0f };
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
        DrawModel(model, (Vector3){ 0, 0, 0 }, 1.0f, WHITE);
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawText("GenMeshHeightmap Example", 10, 10, 20, DARKGRAY);
        DrawTextureEx(heightmapTexture, (Vector2){600, 50}, 0.0f, 0.2f, WHITE); // Show heightmap preview

        EndDrawing();
    }

    // Cleanup
    UnloadModel(model);
    UnloadTexture(texture);
    UnloadTexture(heightmapTexture);
    CloseWindow();

    return 0;
}

