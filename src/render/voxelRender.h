#ifndef VOXELRENDER_H
#define VOXELRENDER_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "../core/voxel.h"
#include "../core/world.h"
#include "../math/voxelMath.h"
#include "../core/face.h"

class VoxelRender : public World {

    
public:
    static void DrawFace(Face, Camera);
};

#endif // VOXELRENDER_H