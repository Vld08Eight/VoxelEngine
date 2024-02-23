#ifndef MACROBLOCK_H
#define MACROBLOCK_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <string> 
#include "voxel.h"

class Macroblock {
private:
    int div = 16;
    float size;
    Voxel type;
    Vector3 coordinates;
    
public:
    Macroblock(Voxel);
    void setType(Voxel);
    Voxel getType();
    void setDiv(int);
    int getDiv();
    float getSize();
    Vector3 getCoordinates();
};

#endif // MACROBLOCK_H