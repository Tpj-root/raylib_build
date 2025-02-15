#include "raylib.h"
#include "raymath.h"  // Include this for MatrixTranslate()

int main() {
    InitWindow(800, 600, "DrawMesh Example");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 4.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Mesh cubeMesh = GenMeshCube(2.0f, 2.0f, 2.0f);
    Material material = LoadMaterialDefault();

    Matrix transform = MatrixTranslate(0.0f, 1.0f, 0.0f);  // Now it will work

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawMesh(cubeMesh, material, transform);
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawText("DrawMesh() Example", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadMesh(cubeMesh);
    CloseWindow();
    return 0;
}

