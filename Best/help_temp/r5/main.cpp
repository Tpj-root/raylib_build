#include "raylib.h"
#include "raymath.h"

int main() {
    InitWindow(800, 600, "Cube with Texture");
    Camera camera = { 0 };
    camera.position = (Vector3){ 3.0f, 3.0f, 3.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model model = LoadModel("cube.obj");
    Texture2D texture = LoadTexture("rubik_texture.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        DrawModel(model, (Vector3){0.0f, 0.0f, 0.0f}, 1.0f, WHITE);
        EndMode3D();
        DrawText("Cube with Texture", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadModel(model);
    CloseWindow();

    return 0;
}
