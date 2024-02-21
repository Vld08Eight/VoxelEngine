#ifndef VOXEL_H
#define VOXEL_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <string> 
#include "world.h"

class Voxel : public World{
protected:
    Vector3 cubeSize = { 0.1f, 0.1f, 0.1f };
    
public:
    //Voxel(void);
    //~Voxel(void);
    void drawVoxelWires(Vector3 dots3D[], Color color);
    bool onScreen(Vector3);
    Vector3* getDots(int, int, int);
};

#endif // VOXEL_H
