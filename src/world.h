#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <string> 
#include "voxel.h"

class World {

    
public:
    Camera camera = { 0 };
    World();
    void drawVoxelWires(Voxel, Vector3 dots3D[]);
    bool onScreen(Vector3);
    Vector3* getDots(Voxel);
};

#endif // VOXEL_H