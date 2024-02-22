#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <string> 

class World {

    
public:
    Camera camera = { 0 };
    World();
    //Camera getCamera();
};

#endif // VOXEL_H