#ifndef VOXELRENDER_H
#define VOXELRENDER_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "../core/voxel.h"
#include "../core/world.h"
#include "../math/voxelMath.h"
#include "../core/face.h"

class VoxelRender{

    
public:
    static void DrawFaceWires(Face, Camera);
    static void DrawFace(Face, Camera, Color);
    static void DrawVoxelWires(Voxel, Camera);
    static void DrawVoxelFaces(Voxel, Camera, Color);
};

#endif // VOXELRENDER_H