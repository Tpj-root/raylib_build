#ifndef CUBE_H
#define CUBE_H

#include <raylib.h>

class Cube {
public:
    Cube();
    ~Cube();

    void Draw(); // Draw the cube
    void RotateFace(int face, bool clockwise); // Rotate a specific face
    void Shuffle(); // Shuffle the cube

private:
    Color faces[6][3][3]; // 6 faces, each 3x3
    void InitializeFaces(); // Initialize the cube with colors
    void DrawFace(int face, Vector3 position); // Draw a single face
    void RotateMatrix(Color mat[3][3], bool clockwise); // Rotate a 3x3 matrix
};

#endif