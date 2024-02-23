#include "voxel.h"

Voxel::Voxel(Vector3 coordinates){
    this->coordinates = coordinates;
    this->isEmpty_flag = false;
}

Voxel::Voxel(){
    this->isEmpty_flag = true;
}

bool Voxel::isEmpty(){
    return this->isEmpty_flag;
}

float Voxel::getCubeSize(){
    return this->cubeSize;
}

Vector3 Voxel::getCoordinates(){
    return this->coordinates;
}