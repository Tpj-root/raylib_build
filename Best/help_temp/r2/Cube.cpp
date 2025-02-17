#include "Cube.h"

Cube::Cube() {
    InitializeFaces();
}

Cube::~Cube() {
    // Destructor
}

void Cube::InitializeFaces() {
    // Define colors for each face
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
            DrawCubeWires(cubePosition, 1.8f, 1.8f, 1.8f, BLACK);
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

    // Draw all 6 faces
    for (int face = 0; face < 6; face++) {
        DrawFace(face, positions[face]);
    }
}

void Cube::RotateMatrix(Color mat[3][3], bool clockwise) {
    // Rotate a 3x3 matrix clockwise or counter-clockwise
    Color temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (clockwise) {
                temp[i][j] = mat[2 - j][i];
            } else {
                temp[i][j] = mat[j][2 - i];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = temp[i][j];
        }
    }
}

void Cube::RotateFace(int face, bool clockwise) {
    // Rotate the specified face
    RotateMatrix(faces[face], clockwise);

    // Rotate the adjacent edges (not implemented in this example)
    // You can expand this function to handle edge rotations.
}

void Cube::Shuffle() {
    // Shuffle the cube by performing random rotations
    for (int i = 0; i < 20; i++) {
        int face = GetRandomValue(0, 5);
        bool clockwise = GetRandomValue(0, 1);
        RotateFace(face, clockwise);
    }
}