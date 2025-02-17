#ifndef ROTATED_PLANE_H
#define ROTATED_PLANE_H

#include "raylib.h"
#include "rlgl.h"

class RotatedPlane {
public:
    RotatedPlane(Vector3 position, Vector2 size, Color color, float angle, Vector3 axis);

    void Draw() const;

private:
    Vector3 position;
    Vector2 size;
    Color color;
    float angle;
    Vector3 axis;
};

#endif // ROTATED_PLANE_H