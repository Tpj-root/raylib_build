/*******************************************************************************************
*
*   raylib [models] example - Draw textured cube
*
*   Example complexity rating: [★★☆☆] 2/4
*
*   Example originally created with raylib 4.5, last time updated with raylib 4.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2022-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <stdio.h>
#include "rlgl.h"       // Required to define vertex data (immediate-mode style)

//------------------------------------------------------------------------------------
// Custom Functions Declaration
//------------------------------------------------------------------------------------
void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color); // Draw cube textured
void DrawCubeTextureRec(Texture2D texture, Rectangle source, Vector3 position, float width, float height, float length, Color color); // Draw cube with a region of a texture

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - draw cube texture");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    // Load texture to be applied to the cubes sides
    Texture2D texture = LoadTexture("resources/256.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_THIRD_PERSON);   // best
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw cube with an applied texture
                //DrawCubeTexture(texture, (Vector3){ -2.0f, 2.0f, 0.0f }, 2.0f, 4.0f, 2.0f, WHITE);

                // Draw cube with an applied texture, but only a defined rectangle piece of the texture
               DrawCubeTextureRec(texture, (Rectangle){ 0.0f, texture.height/2.0f, texture.width/2.0f, texture.height/2.0f }, 
                    (Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, WHITE);

                DrawGrid(10, 1.0f);        // Draw a grid

            EndMode3D();

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture); // Unload texture
    
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Custom Functions Definition
//------------------------------------------------------------------------------------
// Draw cube textured
// NOTE: Cube position is the center position
void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;


    // Set desired texture to be enabled while drawing following vertex data
    rlSetTexture(texture.id);

    // Vertex data transformation can be defined with the commented lines,
    // but in this example we calculate the transformed vertex data directly when calling rlVertex3f()
    //rlPushMatrix();
        // NOTE: Transformation is applied in inverse order (scale -> rotate -> translate)
        //rlTranslatef(2.0f, 0.0f, 0.0f);
        //rlRotatef(45, 0, 1, 0);
        //rlScalef(2.0f, 2.0f, 2.0f);

        rlBegin(RL_QUADS);
            rlColor4ub(color.r, color.g, color.b, color.a);
            // Front Face
            rlNormal3f(0.0f, 0.0f, 1.0f);       // Normal Pointing Towards Viewer
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);  // Top Left Of The Texture and Quad
            // Back Face
            rlNormal3f(0.0f, 0.0f, - 1.0f);     // Normal Pointing Away From Viewer
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);  // Bottom Left Of The Texture and Quad
            // Top Face
            rlNormal3f(0.0f, 1.0f, 0.0f);       // Normal Pointing Up
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);  // Top Right Of The Texture and Quad
            // Bottom Face
            rlNormal3f(0.0f, - 1.0f, 0.0f);     // Normal Pointing Down
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            // Right face
            rlNormal3f(1.0f, 0.0f, 0.0f);       // Normal Pointing Right
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            // Left Face
            rlNormal3f( - 1.0f, 0.0f, 0.0f);    // Normal Pointing Left
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);  // Top Left Of The Texture and Quad
        rlEnd();
    //rlPopMatrix();

    rlSetTexture(0);
}

// Draw cube with texture piece applied to all faces
void DrawCubeTextureRec(Texture2D texture, Rectangle source, Vector3 position, float width, float height, float length, Color color)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;
    float texWidth = (float)texture.width;
    float texHeight = (float)texture.height;

    //printf("position x: %.2f, position y: %.2f, position z: %.2f\n", x, y, z);
    //printf("texWidth: %.2f, texHeight: %.2f", texWidth, texHeight);



    // Set desired texture to be enabled while drawing following vertex data
    rlSetTexture(texture.id);
    // We calculate the normalized texture coordinates for the desired texture-source-rectangle
    // It means converting from (tex.width, tex.height) coordinates to [0.0f, 1.0f] equivalent 
    rlBegin(RL_QUADS);
        rlColor4ub(color.r, color.g, color.b, color.a);
        //printf("color_r : %.2f,color_g: %.2f,color_b : %.2f,color_a: %.2f", color.r, color.g, color.b, color.a);
       //        DrawCubeTextureRec(texture, (Rectangle){ 0.0f, texture.height/2.0f, texture.width/2.0f, texture.height/2.0f }, (Vector3){ 2.0f, 5.0f, 5.0f }, 2.0f, 2.0f, 2.0f, WHITE);

        // Front face
        rlNormal3f(0.0f, 0.0f, 1.0f);
        rlTexCoord2f(source.x/256, (source.y + source.height)/256);
        printf(" -------- Start -------\n");
        printf("1st point of  2d Texture\n");
        printf("source.x = %.2f x , source.y : %.2f  y \n", source.x/256, (source.y + source.height)/256);
        //printf("position x: %.2f, position y: %.2f, position z: %.2f\n", x, y, z);
        rlVertex3f(x - width/2, y - height/2, z + length/2);
        printf("Vaue_of_x = %.2f x , Vaue_of_y  : %.2f  y , Vaue_of_z : %.2f  z \n", x - width/2, y - height/2, z + length/2 );
        //printf("Vaue_of_width = %.2f x , Vaue_of_height  : %.2f  y , Vaue_of_length : %.2f  z \n", width, height , length );
        //printf("rlVertex3f.x = %.2f x , rlVertex3f.y : %.2f  y , rlVertex3f.z: %.2f  z \n", x - width/2, y - height/2, z + length/2);
        //printf("position x: %.2f, position y: %.2f, position z: %.2f\n", x, y, z);
        rlTexCoord2f((source.x + source.width)/256, (source.y + source.height)/256);
        printf("2nd point of  2d Texture\n");
        printf("source.x = %.2f x , source.y : %.2f  y \n", (source.x + source.width)/256, (source.y + source.height)/256);
//
        rlVertex3f(x + width/2, y - height/2, z + length/2);
        printf("Vaue_of_x = %.2f x , Vaue_of_y  : %.2f  y , Vaue_of_z : %.2f  z \n", x + width/2, y - height/2, z + length/2);

        rlTexCoord2f((source.x + source.width)/256, source.y/256);
        printf("3rd point of  2d Texture\n");
        printf("source.x = %.2f x , source.y : %.2f  y \n", (source.x + source.width)/256, source.y/256);

        rlVertex3f(x + width/2, y + height/2, z + length/2);
        printf("Vaue_of_x = %.2f x , Vaue_of_y  : %.2f  y , Vaue_of_z : %.2f  z \n", x + width/2, y + height/2, z + length/2);

        rlTexCoord2f(source.x/256, source.y/256);
        printf("4th point of  2d Texture \n");
        printf("source.x = %.2f x , source.y : %.2f  y \n", source.x/256, source.y/256);

        rlVertex3f(x - width/2, y + height/2, z + length/2);
        printf("Vaue_of_x = %.2f x , Vaue_of_y  : %.2f  y , Vaue_of_z : %.2f  z \n", x - width/2, y + height/2, z + length/2);
        printf(" -------- end -------\n");


        // Back face
//        rlNormal3f(0.0f, 0.0f, - 1.0f);
//        rlTexCoord2f((source.x + source.width)/256, (source.y + source.height)/256);
//        rlVertex3f(x - width/2, y - height/2, z - length/2);
//        rlTexCoord2f((source.x + source.width)/256, source.y/256);
//        rlVertex3f(x - width/2, y + height/2, z - length/2);
//        rlTexCoord2f(source.x/256, source.y/256);
//        rlVertex3f(x + width/2, y + height/2, z - length/2);
//        rlTexCoord2f(source.x/256, (source.y + source.height)/256);
//        rlVertex3f(x + width/2, y - height/2, z - length/2);
//
//        // Top face
//        rlNormal3f(0.0f, 1.0f, 0.0f);
//        rlTexCoord2f(source.x/256, source.y/256);
//        rlVertex3f(x - width/2, y + height/2, z - length/2);
//        rlTexCoord2f(source.x/256, (source.y + source.height)/256);
//        rlVertex3f(x - width/2, y + height/2, z + length/2);
//        rlTexCoord2f((source.x + source.width)/256, (source.y + source.height)/256);
//        rlVertex3f(x + width/2, y + height/2, z + length/2);
//        rlTexCoord2f((source.x + source.width)/256, source.y/256);
//        rlVertex3f(x + width/2, y + height/2, z - length/2);
//
//        // Bottom face
//        rlNormal3f(0.0f, - 1.0f, 0.0f);
//        rlTexCoord2f((source.x + source.width)/256, source.y/256);
//        rlVertex3f(x - width/2, y - height/2, z - length/2);
//        rlTexCoord2f(source.x/256, source.y/256);
//        rlVertex3f(x + width/2, y - height/2, z - length/2);
//        rlTexCoord2f(source.x/256, (source.y + source.height)/256);
//        rlVertex3f(x + width/2, y - height/2, z + length/2);
//        rlTexCoord2f((source.x + source.width)/256, (source.y + source.height)/256);
//        rlVertex3f(x - width/2, y - height/2, z + length/2);
//
//        // Right face
//        rlNormal3f(1.0f, 0.0f, 0.0f);
//        rlTexCoord2f((source.x + source.width)/256, (source.y + source.height)/256);
//        rlVertex3f(x + width/2, y - height/2, z - length/2);
//        rlTexCoord2f((source.x + source.width)/256, source.y/256);
//        rlVertex3f(x + width/2, y + height/2, z - length/2);
//        rlTexCoord2f(source.x/256, source.y/256);
//        rlVertex3f(x + width/2, y + height/2, z + length/2);
//        rlTexCoord2f(source.x/256, (source.y + source.height)/256);
//        rlVertex3f(x + width/2, y - height/2, z + length/2);
//
//        // Left face
//        rlNormal3f( - 1.0f, 0.0f, 0.0f);
//        rlTexCoord2f(source.x/256, (source.y + source.height)/256);
//        rlVertex3f(x - width/2, y - height/2, z - length/2);
//        rlTexCoord2f((source.x + source.width)/256, (source.y + source.height)/256);
//        rlVertex3f(x - width/2, y - height/2, z + length/2);
//        rlTexCoord2f((source.x + source.width)/256, source.y/256);
//        rlVertex3f(x - width/2, y + height/2, z + length/2);
//        rlTexCoord2f(source.x/256, source.y/256);
//        rlVertex3f(x - width/2, y + height/2, z - length/2);

    rlEnd();

    rlSetTexture(0);
}





//// Function to print the values
//void printValues(float x, float y, float z, float width, float height, float length, 
//                 float texWidth, float texHeight, Vector2 source)
//{
//
//    printf("texWidth: %.2f, texHeight: %.2f\n", texWidth, texHeight);
//    printf("Texture Source: x: %.2f, y: %.2f, width: %.2f, height: %.2f\n", 
//           source.x, source.y, source.width, source.height);
//    
//    // Print the texture coordinates and vertex positions
//    printf("Texture Coordinates and Vertex Positions:\n");
//
//    printf("TexCoord1: (%.2f, %.2f), Vertex1: (%.2f, %.2f, %.2f)\n", 
//           source.x/texWidth, (source.y + source.height)/texHeight, 
//           x - width/2, y - height/2, z + length/2);
//
//    printf("TexCoord2: (%.2f, %.2f), Vertex2: (%.2f, %.2f, %.2f)\n", 
//           (source.x + source.width)/texWidth, (source.y + source.height)/texHeight, 
//           x + width/2, y - height/2, z + length/2);
//
//    printf("TexCoord3: (%.2f, %.2f), Vertex3: (%.2f, %.2f, %.2f)\n", 
//           (source.x + source.width)/texWidth, source.y/texHeight, 
//           x + width/2, y + height/2, z + length/2);
//
//    printf("TexCoord4: (%.2f, %.2f), Vertex4: (%.2f, %.2f, %.2f)\n", 
//           source.x/texWidth, source.y/texHeight, 
//           x - width/2, y + height/2, z + length/2);
//}
