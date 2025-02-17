#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include <raylib.h>

class RubiksCube {
public:
    RubiksCube();
    ~RubiksCube();

    void Draw();
    void RotateFront(bool clockwise);
    void RotateBack(bool clockwise);

private:
    Color faces[6][3][3]; // 6 faces, each 3x3
    void InitializeFaces();
    void DrawFace(int face, Vector3 position);
};

#endif