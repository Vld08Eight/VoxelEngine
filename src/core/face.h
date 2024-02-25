#ifndef FACE_H
#define FACE_H

#include "raylib.h"
#include "math.h"
#include <iostream>


class Face{
private:
    float size = 0.1f;
    Vector3 coordinates[4];
    Color color = GREEN;
public:
    Face(){}
    Face(Vector3 coordinates[4]);
    float getSize();
    Vector3* getFaceDots();
    Color getColor();
    void setColor(Color);
};

#endif // FACE_H
