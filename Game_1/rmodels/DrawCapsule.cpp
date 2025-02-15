#include "raylib.h"

int main() {
    InitWindow(800, 600, "DrawCapsule Example");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 8.0f, 8.0f, 12.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Looking at the capsule
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Define capsule parameters
        Vector3 startPos = { -1.5f, -2.0f, 0.0f };  // Capsule base position
        Vector3 endPos = { 1.5f, 2.0f, 0.0f };      // Capsule top position

        Vector3 WstartPos = { -10.5f, -2.0f, 0.0f };  // Capsule base position
        Vector3 WendPos = { 10.5f, 2.0f, 0.0f };      // Capsule top position


        float radius = 0.8f;   // Capsule radius
        int slices = 16;       // Number of slices (longitude)
        int rings = 8;         // Number of rings (latitude)

        // Draw the solid capsule
        DrawCapsule(startPos, endPos, radius, slices, rings, BLUE);

        // Draw the capsule wireframe
        DrawCapsuleWires(WstartPos, WendPos, radius, slices, rings, BLACK);

        EndMode3D();

        DrawText("3D Capsule & Capsule Wireframe Example", 10, 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

