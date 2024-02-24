#ifndef VOXELFACES_H
#define VOXELFACES_H

#include "raylib.h"
#include "math.h"
#include <iostream> 
#include "face.h"
#include "../math/voxelMath.h"

class VoxelFaces: public Face{
private:
    float size = 0.1f;
    Face faces[6];
public:
    VoxelFaces() {}
    VoxelFaces(Vector3);
    Face getFaceByNum(int);
};

#endif // VOXELFACES_H
