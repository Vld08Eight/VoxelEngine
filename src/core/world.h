#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "voxel.h"

class World {

    
public:
    Camera camera = { 0 };
    World();
};

#endif // WORLD_H