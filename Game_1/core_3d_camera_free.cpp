#include "raylib.h"
#include <stdio.h> // For sprintf

void DrawColoredCube(Vector3 position, float size) {
    Vector3 v0 = { position.x - size/2, position.y - size/2, position.z - size/2 };
    Vector3 v1 = { position.x + size/2, position.y - size/2, position.z - size/2 };
    Vector3 v2 = { position.x + size/2, position.y + size/2, position.z - size/2 };
    Vector3 v3 = { position.x - size/2, position.y + size/2, position.z - size/2 };
    Vector3 v4 = { position.x - size/2, position.y - size/2, position.z + size/2 };
    Vector3 v5 = { position.x + size/2, position.y - size/2, position.z + size/2 };
    Vector3 v6 = { position.x + size/2, position.y + size/2, position.z + size/2 };
    Vector3 v7 = { position.x - size/2, position.y + size/2, position.z + size/2 };

    // Front face (Red)
    DrawTriangle3D(v0, v1, v2, RED);
    DrawTriangle3D(v0, v2, v3, RED);

    // Back face (Blue)
    DrawTriangle3D(v4, v5, v6, BLUE);
    DrawTriangle3D(v4, v6, v7, BLUE);

    // Left face (Green)
    DrawTriangle3D(v0, v3, v7, GREEN);
    DrawTriangle3D(v0, v7, v4, GREEN);

    // Right face (Yellow)
    DrawTriangle3D(v1, v5, v6, YELLOW);
    DrawTriangle3D(v1, v6, v2, YELLOW);

    // Top face (White)
    DrawTriangle3D(v3, v2, v6, GRAY);
    DrawTriangle3D(v3, v6, v7, GRAY);

    // Bottom face (Orange)
    DrawTriangle3D(v0, v1, v5, ORANGE);
    DrawTriangle3D(v0, v5, v4, ORANGE);
}


void DrawSolidColoredCube(Vector3 position, float size) {
    // Define colors for each face
    Color frontColor = GREEN;
    Color backColor = BLUE;
    Color leftColor = RED; // chnage the color like cube
    Color rightColor = ORANGE; //
    Color topColor = GRAY; // GraY
    Color bottomColor = YELLOW;

    // Draw the solid cube
    DrawCubeV(position, (Vector3){ size, size, size }, WHITE); // Base cube
    DrawCubeWiresV(position, (Vector3){ size, size, size }, BLACK); // Outline

    // Draw colored faces
    DrawCubeV((Vector3){ position.x, position.y, position.z - size/2 }, (Vector3){ size, size, 0.01f }, frontColor);  // Front
    DrawCubeV((Vector3){ position.x, position.y, position.z + size/2 }, (Vector3){ size, size, 0.01f }, backColor);   // Back
    DrawCubeV((Vector3){ position.x - size/2, position.y, position.z }, (Vector3){ 0.01f, size, size }, leftColor);   // Left
    DrawCubeV((Vector3){ position.x + size/2, position.y, position.z }, (Vector3){ 0.01f, size, size }, rightColor);  // Right
    DrawCubeV((Vector3){ position.x, position.y + size/2, position.z }, (Vector3){ size, 0.01f, size }, topColor);    // Top
    DrawCubeV((Vector3){ position.x, position.y - size/2, position.z }, (Vector3){ size, 0.01f, size }, bottomColor); // Bottom

    // Draw 3x3 grid lines on the front face
    float step = size / 3;
    for (int i = -1; i <= 1; i++) {
        Vector3 v1 = { position.x - size / 2, position.y + step * i, position.z - size / 2 };
        Vector3 v2 = { position.x + size / 2, position.y + step * i, position.z - size / 2 };
        Vector3 v3 = { position.x + step * i, position.y - size / 2, position.z - size / 2 };
        Vector3 v4 = { position.x + step * i, position.y + size / 2, position.z - size / 2 };

        DrawLine3D(v1, v2, BLACK); // Horizontal lines
        DrawLine3D(v3, v4, BLACK); // Vertical lines
    }
}


Camera3D InitCamera(Vector3 position, Vector3 target, Vector3 up, float fovy) {
    Camera3D cam = { 0 };
    cam.position = position;
    cam.target = target;
    cam.up = up;
    cam.fovy = fovy;
    cam.projection = CAMERA_PERSPECTIVE;
    return cam;
}




int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3D camera free");

    // 1  Camera (Top View)
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 5.0f, 0.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 1.0f, 0.0f, 0.0f };          // Camera up vector
    camera.fovy = 45.0f;                                // Field-of-view
    camera.projection = CAMERA_PERSPECTIVE;            // Perspective mode

    // 2 Camera (Down View)
    Camera3D camera2 = { 0 };
    camera2.position = (Vector3){ 0.0f, -5.0f, 0.0f }; 
    camera2.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera2.up = (Vector3){ 1.0f, 0.0f, 0.0f };
    camera2.fovy = 45.0f;
    camera2.projection = CAMERA_PERSPECTIVE;


    // 3 Camera (Front View)
    Camera3D camera3 = { 0 };
    camera3.position = (Vector3){ 0.0f, 0.0f, 5.0f }; 
    camera3.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera3.up = (Vector3){ 0.0f, 1.0f, 0.0f }; 
    camera3.fovy = 45.0f;
    camera3.projection = CAMERA_PERSPECTIVE;


    // 3 Camera (Back View)
    Camera3D camera4 = { 0 };
    camera4.position = (Vector3){ 0.0f, 0.0f, -5.0f }; 
    camera4.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera4.up = (Vector3){ 0.0f, 1.0f, 0.0f }; 
    camera4.fovy = 45.0f;
    camera4.projection = CAMERA_PERSPECTIVE;


    // 3 Camera (Left View)
    Camera3D camera5 = { 0 };
    camera5.position = (Vector3){ 5.0f, 0.0f, 0.0f }; 
    camera5.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera5.up = (Vector3){ 0.0f, 1.0f, 0.0f }; 
    camera5.fovy = 45.0f;
    camera3.projection = CAMERA_PERSPECTIVE;


    // 3 Camera (Right View)
    Camera3D camera6 = { 0 };
    camera6.position = (Vector3){ -5.0f, 0.0f, 0.0f }; 
    camera6.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera6.up = (Vector3){ 0.0f, 1.0f, 0.0f }; 
    camera6.fovy = 45.0f;
    camera6.projection = CAMERA_PERSPECTIVE;




    int activeCamera = 1; // 1 = camera1, 2 = camera2

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //UpdateCamera(&camera, CAMERA_FREE);

        //if (IsKeyPressed(KEY_Z)) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

        if (IsKeyPressed(KEY_SPACE)) 
        {
            activeCamera++;
            if (activeCamera > 6) activeCamera = 1; // Reset to 1 after 6
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            //BeginMode3D(camera);
            // Add one more camera
               BeginMode3D(activeCamera == 1 ? camera : 
                           activeCamera == 2 ? camera2 : 
                           activeCamera == 3 ? camera3 : 
                           activeCamera == 4 ? camera4 : 
                           activeCamera == 5 ? camera5 : 
                                               camera6);
                //DrawColoredCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f);
                DrawSolidColoredCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f);
                DrawGrid(10, 1.0f);
            EndMode3D();

            // UI Background
            DrawRectangle(10, 10, 300, 100, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(10, 10, 300, 100, RED);

            // Camera details
            char buffer[128];
            sprintf(buffer, "camera.position: (%.2f, %.2f, %.2f)", camera.position.x, camera.position.y, camera.position.z);
            DrawText(buffer, 20, 20, 10, BLACK);

            sprintf(buffer, "camera.target: (%.2f, %.2f, %.2f)", camera.target.x, camera.target.y, camera.target.z);
            DrawText(buffer, 20, 35, 10, BLACK);

            sprintf(buffer, "camera.up: (%.2f, %.2f, %.2f)", camera.up.x, camera.up.y, camera.up.z);
            DrawText(buffer, 20, 50, 10, BLACK);

            sprintf(buffer, "camera.fovy: %.2f", camera.fovy);
            DrawText(buffer, 20, 65, 10, BLACK);

            sprintf(buffer, "projection: %s", camera.projection == CAMERA_PERSPECTIVE ? "PERSPECTIVE" : "ORTHOGRAPHIC");
            DrawText(buffer, 20, 80, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
