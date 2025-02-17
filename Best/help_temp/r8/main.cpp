#include "raylib.h"

int main(void)
{
    // Initialize window
    const int screenWidth = 1200;
    const int screenHeight = 750;
    InitWindow(screenWidth, screenHeight, "Raylib 3D Skybox Example");

    // Set up a 3D camera
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 6.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };   // Look at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };       // Up vector
    camera.fovy = 45.0f;                             // Field of view
    camera.projection = CAMERA_PERSPECTIVE;         // Perspective mode

    // Load skybox cubemap texture (6 faces in one image)
    //TextureCubemap skyboxTexture = LoadTextureCubemap(LoadTexture("rubik_texture_2.png"), CUBEMAP_LAYOUT_AUTO_DETECT);
    // Load image first, then convert to cubemap texture
    Image cubemapImage = LoadImage("rubik_texture_2.png");  
    TextureCubemap skyboxTexture = LoadTextureCubemap(cubemapImage, CUBEMAP_LAYOUT_AUTO_DETECT);
    UnloadImage(cubemapImage);  // Free the image after conversion


    // Create a cube model to act as a skybox
    Mesh cubeMesh = GenMeshCube(10.0f, 10.0f, 10.0f);
    Model skybox = LoadModelFromMesh(cubeMesh);
    SetMaterialTexture(&skybox.materials[0], MATERIAL_MAP_CUBEMAP, skyboxTexture);
    skybox.materials[0].shader = LoadShader(0, "resources/shaders/skybox.fs");

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main loop
    {
        // Update camera
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
            DrawModel(skybox, (Vector3){ 0, 0, 0 }, 1.0f, WHITE); // Render the skybox cube
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
