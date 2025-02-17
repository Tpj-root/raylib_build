#include "RubiksCube.h"

RubiksCube::RubiksCube() {
    InitializeFaces();
}

RubiksCube::~RubiksCube() {
    // Destructor
}

void RubiksCube::InitializeFaces() {
    Color colors[6] = { RED, GREEN, BLUE, YELLOW, ORANGE, WHITE };
    for (int face = 0; face < 6; face++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                faces[face][i][j] = colors[face];
            }
        }
    }
}

void RubiksCube::DrawFace(int face, Vector3 position) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Vector3 cubePosition = {
                position.x + j * 2.0f,
                position.y - i * 2.0f,
                position.z
            };
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, faces[face][i][j]);
        }
    }
}

void RubiksCube::Draw() {
    Vector3 positions[6] = {
        { 0, 0, 10 },  // Front
        { 0, 0, -10 }, // Back
        { -10, 0, 0 }, // Left
        { 10, 0, 0 },  // Right
        { 0, 10, 0 },  // Up
        { 0, -10, 0 }  // Down
    };

    for (int face = 0; face < 6; face++) {
        DrawFace(face, positions[face]);
    }
}

void RubiksCube::RotateFront(bool clockwise) {
    // Rotate the front face
    // This is a placeholder for the rotation logic
}

void RubiksCube::RotateBack(bool clockwise) {
    // Rotate the back face
    // This is a placeholder for the rotation logic
}