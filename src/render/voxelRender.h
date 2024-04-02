#ifndef VOXELRENDER_H
#define VOXELRENDER_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "../core/Voxel.h"
#include "../core/World.h"
#include "../math/VoxelMath.h"
#include "../core/Face.h"
#include <vector>
#include <algorithm>

class VoxelRender{

    
public:
    static void DrawFaceWires(Face, Camera);
    static void DrawFace(Face, Camera);
    static void DrawVoxelWires(Voxel, Camera);
    static void DrawVoxelFaces(Voxel, Camera);
};

#endif // VOXELRENDER_H