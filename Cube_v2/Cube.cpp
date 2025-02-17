#include "Cube.h"

Cube::Cube() {
    InitializeFaces();
}

Cube::~Cube() {
    // Destructor
}

void Cube::InitializeFaces() {
    // Define colors for each face
    // colors[6] = { RED };

    Color colors[6] = { RED, GREEN, BLUE, YELLOW, ORANGE, WHITE };

    // Initialize each face with its respective color
    for (int face = 0; face < 6; face++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                faces[face][i][j] = colors[face];
            }
        }
    }
}

void Cube::DrawFace(int face, Vector3 position) {
    // Draw a single face of the cube
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Vector3 cubePosition = {
                position.x + j * 2.0f,
                position.y - i * 2.0f,
                position.z
            };
            DrawCube(cubePosition, 1.8f, 1.8f, 1.8f, faces[face][i][j]);
            //DrawCubeWires(cubePosition, 1.8f, 1.8f, 1.8f, BLACK);
        }
    }
}

void Cube::Draw() {
    // Define positions for each face
    Vector3 positions[6] = {
        { 0, 0, 3 },   // Front
        { 0, 0, -3 },  // Back
        { -3, 0, 0 }, // Left
        { 3, 0, 0 },   // Right
        { 0, 3, 0 },   // Up
        { 0, -3, 0 }   // Down
    };

void Cube::DrawRotatedPlane(Vector3 position, Vector2 size, Color color, float angle, Vector3 axis) {
    rlPushMatrix();
    rlTranslatef(position.x, position.y, position.z);
    rlRotatef(angle, axis.x, axis.y, axis.z);
    DrawPlane((Vector3){ 0, 0, 0 }, size, color);
    rlPopMatrix();
}
