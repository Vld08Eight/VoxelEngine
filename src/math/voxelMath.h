#ifndef VOXELMATH_H
#define VOXELMATH_H

#include "raylib.h"
#include "math.h"
#include <iostream>
//#include "../core/voxel.h"
#include "../core/face.h"

class VoxelMath {

    
public:
    static bool onScreen(Camera, Vector3);
    static float getVec3Distance(Vector3, Vector3);
    static Face getVoxelFaces(Vector3, float, int);
    static Vector3 arrToWorld(Vector3, float);
    static Vector3 vec3Multiply(Vector3, Vector3);
    static Vector3 getfaceNormal(Face);
};

#endif // VOXELMATH_H