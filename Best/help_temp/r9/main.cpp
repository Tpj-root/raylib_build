#include "raylib.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else
    #define GLSL_VERSION            100
#endif

// Function to create a cube with individual textures on each face
Model CreateTexturedCube(Texture2D textures[6]) {
    // Create the basic cube mesh
    Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);  // Create a cube mesh with 1x1x1 size

    // Load model from mesh
    Model model = LoadModelFromMesh(cube);

    // Create new texture coordinates for each face (flattened into float array)
    float uv[48] = {
        // Front face
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        // Back face
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        // Left face
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        // Right face
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        // Top face
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        // Bottom face
        0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
    };

    // Assign UVs to the cube's mesh for each face
    cube.texcoords = uv;

    // Assign textures to each face of the cube
    for (int i = 0; i < 6; i++) {
        model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = textures[i];
    }

    return model;
}

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - texture tiling");

    // Load textures for each face of the cube (1.png to 6.png)
    Texture2D textures[6];
    textures[0] = LoadTexture("1.png"); // Front face
    textures[1] = LoadTexture("2.png"); // Back face
    textures[2] = LoadTexture("3.png"); // Left face
    textures[3] = LoadTexture("4.png"); // Right face
    textures[4] = LoadTexture("5.png"); // Top face
    textures[5] = LoadTexture("6.png"); // Bottom face

    // Create the cube model with different textures on each face
    Model cubeModel = CreateTexturedCube(textures);

    // Define the camera to look into our 3D world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 4.0f, 4.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.5f, 0.0f }; // Camera target point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f }; // Camera up vector
    camera.fovy = 45.0f; // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; // Camera projection type

    DisableCursor(); // Limit cursor to relative movement inside the window

    SetTargetFPS(60); // Set the game to run at 60 frames per second

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        UpdateCamera(&camera, CAMERA_FREE);

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                // Draw the cube with assigned textures
                DrawModel(cubeModel, (Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, WHITE);
                DrawGrid(10, 1.0f);
            EndMode3D();

            DrawText("Use mouse to rotate the camera", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // De-Initialization
    UnloadModel(cubeModel); // Unload model
    for (int i = 0; i < 6; i++) {
        UnloadTexture(textures[i]); // Unload textures
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
