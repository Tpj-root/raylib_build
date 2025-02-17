#include "RotatedPlane.h"

RotatedPlane::RotatedPlane(Vector3 position, Vector2 size, Color color, float angle, Vector3 axis)
    : position(position), size(size), color(color), angle(angle), axis(axis) {}

void RotatedPlane::Draw() const {
    rlPushMatrix();
    rlTranslatef(position.x, position.y, position.z);
    rlRotatef(angle, axis.x, axis.y, axis.z);
    DrawPlane({ 0, 0, 0 }, size, color);
    rlPopMatrix();
}
