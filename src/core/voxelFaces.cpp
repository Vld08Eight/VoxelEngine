#include "voxelFaces.h"

VoxelFaces::VoxelFaces(Vector3 coordinates){
    this->faces[0] = VoxelMath::getVoxelFaces(coordinates, this->size,1);;
    this->faces[1] = VoxelMath::getVoxelFaces(coordinates, this->size,2);
    this->faces[2] = VoxelMath::getVoxelFaces(coordinates, this->size,3);
    this->faces[3] = VoxelMath::getVoxelFaces(coordinates, this->size,4);
    this->faces[4] = VoxelMath::getVoxelFaces(coordinates, this->size,5);
    this->faces[5] = VoxelMath::getVoxelFaces(coordinates, this->size,6);
}

Face VoxelFaces::getFaceByNum(int num){
    return this->faces[num];
}