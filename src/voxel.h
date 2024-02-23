#ifndef VOXEL_H
#define VOXEL_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <string> 


class Voxel{
private:
    float cubeSize = 0.1f;
    bool isEmpty_flag = true;
    Vector3 coordinates;
public:
    Voxel(Vector3);
    Voxel();
    //~Voxel(void);
    bool isEmpty();
    float getCubeSize();
    Vector3 getCoordinates();
};

#endif // VOXEL_H
