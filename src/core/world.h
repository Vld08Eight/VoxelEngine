#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "voxel.h"

class World {
    Voxel** worldArr;
    int size;
    
public:
    Camera camera = { 0 };
    World(int);
    ~World();
    void setVoxelByIndex(int,int,int);
    Voxel getVoxelByIndex(int,int,int);
};

#endif // WORLD_H