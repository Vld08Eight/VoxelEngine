#include "voxelFaces.h"

VoxelFaces::VoxelFaces(Vector3 coordinates){
    Face* setFaces = VoxelMath::getVoxelFaces(coordinates, this->size);
    std::cout << setFaces[0].getSize() << std::endl;
    this->faces[0] = setFaces[0];
    this->faces[1] = setFaces[1];
    this->faces[2] = setFaces[2];
    this->faces[3] = setFaces[3];
    this->faces[4] = setFaces[4];
    this->faces[5] = setFaces[5];
}

Face VoxelFaces::getFaceByNum(int num){
    return this->faces[num];
}