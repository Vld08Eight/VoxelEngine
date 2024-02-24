#ifndef FACE_H
#define FACE_H

#include "raylib.h"
#include "math.h"
#include <iostream>


class Face{
private:
    float size = 0.1f;
    Vector3 coordinates[4];
public:
    Face(){}
    Face(Vector3 coordinates[4]);
    float getSize();
    Vector3* getFaceDots();
};

#endif // FACE_H
