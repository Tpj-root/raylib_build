#include "raylib.h"
#include "rlgl.h"

void DrawRotatedPlane(Vector3 position, Vector2 size, Color color, float angle, Vector3 axis);
void DrawRotatedGrid(Vector3 position, int slices, float spacing, float angle, Vector3 axis);

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Raylib - Grids & Planes");
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginMode3D(camera);
        
        // Standard grids
        DrawGrid(20, 1.0f);  // XZ Grid (default)
        DrawRotatedGrid((Vector3){ -6.0f, 0.0f, 0.0f }, 20, 1.0f, 90, (Vector3){ 1, 0, 0 });  // XY Grid
        DrawRotatedGrid((Vector3){ 6.0f, 0.0f, 0.0f }, 20, 1.0f, 90, (Vector3){ 0, 1, 0 });   // YZ Grid

        // Rotated grids
        DrawRotatedGrid((Vector3){ 0.0f, 6.0f, 0.0f }, 20, 1.0f, 45, (Vector3){ 1, 0, 0 });  // XY 45° Grid
        DrawRotatedGrid((Vector3){ 0.0f, -6.0f, 0.0f }, 20, 1.0f, 45, (Vector3){ 0, 0, 1 }); // XZ 45° Grid
        DrawRotatedGrid((Vector3){ 0.0f, 0.0f, 6.0f }, 20, 1.0f, 45, (Vector3){ 0, 1, 0 });  // YZ 45° Grid

        // Standard planes
        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 5.0f, 5.0f }, GREEN); // XZ Plane
        DrawRotatedPlane((Vector3){ -6.0f, 0.0f, 0.0f }, (Vector2){ 5.0f, 5.0f }, BLUE, 90, (Vector3){ 1, 0, 0 });  // XY Plane
        DrawRotatedPlane((Vector3){ 6.0f, 0.0f, 0.0f }, (Vector2){ 5.0f, 5.0f }, RED, 90, (Vector3){ 0, 1, 0 });   // YZ Plane

        // Rotated planes
        DrawRotatedPlane((Vector3){ 0.0f, 6.0f, 0.0f }, (Vector2){ 5.0f, 5.0f }, YELLOW, 45, (Vector3){ 1, 0, 0 });  // XY 45° Plane
        DrawRotatedPlane((Vector3){ 0.0f, -6.0f, 0.0f }, (Vector2){ 5.0f, 5.0f }, PURPLE, 45, (Vector3){ 0, 0, 1 }); // XZ 45° Plane
        DrawRotatedPlane((Vector3){ 0.0f, 0.0f, 6.0f }, (Vector2){ 5.0f, 5.0f }, ORANGE, 45, (Vector3){ 0, 1, 0 });  // YZ 45° Plane

        EndMode3D();
        
        DrawText("3D Grids & Planes Example", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Function to draw a rotated plane
void DrawRotatedPlane(Vector3 position, Vector2 size, Color color, float angle, Vector3 axis) {
    rlPushMatrix();
    rlTranslatef(position.x, position.y, position.z);
    rlRotatef(angle, axis.x, axis.y, axis.z);
    DrawPlane((Vector3){ 0, 0, 0 }, size, color);
    rlPopMatrix();
}

// Function to draw a rotated grid
void DrawRotatedGrid(Vector3 position, int slices, float spacing, float angle, Vector3 axis) {
    rlPushMatrix();
    rlTranslatef(position.x, position.y, position.z);
    rlRotatef(angle, axis.x, axis.y, axis.z);
    DrawGrid(slices, spacing);
    rlPopMatrix();
}

