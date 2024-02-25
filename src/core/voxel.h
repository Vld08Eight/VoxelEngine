#ifndef VOXEL_H
#define VOXEL_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "voxelFaces.h"
#include "../math/voxelMath.h"

class Voxel: public VoxelFaces{
private:
    float size = 0.1f;
    bool isEmpty_flag = true;
    Vector3 coordinates;
    //VoxelFaces faces;
public:
    Voxel(){}
    Voxel(Vector3, Color);
    using VoxelFaces::VoxelFaces;
    //~Voxel(void);
    bool isEmpty();
    float getSize();
    Vector3 getCoordinates();
    //VoxelFaces getVoxelFaces();
};

#endif // VOXEL_H
