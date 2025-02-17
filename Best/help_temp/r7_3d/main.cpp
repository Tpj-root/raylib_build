#include "raylib.h"

int main(void)
{
    // Initialize window
    const int screenWidth = 1200;
    const int screenHeight = 750;
    InitWindow(screenWidth, screenHeight, "Raylib 3D Background Example");

    // Set up a 3D camera
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 6.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };   // Look at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };       // Up vector
    camera.fovy = 45.0f;                             // Field of view
    camera.projection = CAMERA_PERSPECTIVE;         // Perspective mode

    // Load skybox texture (ensure the image is seamless)
    Texture2D skyboxTexture = LoadTexture("rubik_texture_2.png"); 

    // Create a large cube to act as a skybox
    Model skybox = LoadModelFromMesh(GenMeshCube(10.0f, 10.0f, 10.0f));
    SetMaterialTexture(&skybox.materials[0], MATERIAL_MAP_ALBEDO, skyboxTexture);

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main loop
    {
        // Update camera
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
            DrawModel(skybox, (Vector3){ 0, 0, 0 }, 1.0f, WHITE); // Render the skybox
        EndMode3D();

        DrawText("Welcome to 3D Raylib!", 20, 20, 20, DARKBLUE);

        EndDrawing();
    }

    // Unload resources
    UnloadTexture(skyboxTexture);
    UnloadModel(skybox);
    CloseWindow();

    return 0;
}
