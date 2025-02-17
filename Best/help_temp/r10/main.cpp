#include "raylib.h"

// Define a Cube with 6 faces and UV mapping for each face
Model CreateTexturedCube(Texture2D* textures) {
    // Define the vertices for a cube
    // 24 vertices (4 vertices for each of the 6 faces)
    float vertices[] = {
        // Front face
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

        // Back face
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        // Top face
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

        // Bottom face
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,

        // Right face
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 1.0f,

        // Left face
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    // Define the indices for the cube faces (6 faces, 2 triangles per face)
    unsigned short indices[] = {
        0, 1, 2, 0, 2, 3,    // Front
        4, 5, 6, 4, 6, 7,    // Back
        8, 9, 10, 8, 10, 11,  // Top
        12, 13, 14, 12, 14, 15, // Bottom
        16, 17, 18, 16, 18, 19, // Right
        20, 21, 22, 20, 22, 23  // Left
    };

    // Create the mesh and model
    Mesh cubeMesh = LoadMeshFromData(vertices, sizeof(vertices), indices, sizeof(indices));
    Model cubeModel = LoadModelFromMesh(cubeMesh);

    // Assign textures to each face
    cubeModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = *textures;

    return cubeModel;
}

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Textured Cube");

    // Load textures for each face of the cube
    Texture2D textures[6];
    textures[0] = LoadTexture("1.png");
    textures[1] = LoadTexture("2.png");
    textures[2] = LoadTexture("3.png");
    textures[3] = LoadTexture("4.png");
    textures[4] = LoadTexture("5.png");
    textures[5] = LoadTexture("6.png");

    // Create the textured cube
    Model cube = CreateTexturedCube(textures);

    // Camera setup
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 4.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 0.5f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update
        UpdateCamera(&camera, CAMERA_FREE);

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawModel(cube, (Vector3){ 0.0f, 0.0f, 0.0f }, 1.0f, WHITE);
            EndMode3D();
            DrawText("3D Textured Cube", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // De-Initialization
    UnloadModel(cube);
    CloseWindow();

    return 0;
}
