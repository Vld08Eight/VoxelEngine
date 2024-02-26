#include "voxel.h"

Voxel::Voxel(Vector3 coordinates, Color color) : VoxelFaces(coordinates){
    this->coordinates = coordinates;
    this->isEmpty_flag = false;
    this->setColor(color);
}

Voxel::Voxel(Color color){
    this->isEmpty_flag = false;
    this->setColor(color);
}

bool Voxel::isEmpty(){
    return this->isEmpty_flag;
}

float Voxel::getSize(){
    return this->size;
}

Vector3 Voxel::getCoordinates(){
    return this->coordinates;
}

//VoxelFaces Voxel::getVoxelFaces(){
//    return this->faces;
//}