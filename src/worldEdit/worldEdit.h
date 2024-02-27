#ifndef WORLDEDIT_H
#define WORLDEDIT_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "../render/voxelRender.h"
#include "../core/world.h"
#include "../core/voxel.h"


class WorldEdit {
    
public:
    static void setVoxel(World, Voxel, Camera, Color);
    static void removeVoxel(World, Voxel);
};

#endif // WORLDEDIT_H