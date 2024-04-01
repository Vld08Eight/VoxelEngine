#include "Voxel.h"

Voxel::Voxel(){}

Voxel::Voxel(Vector3 coordinates){
    this->faces[0] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),1);
    this->faces[1] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),2);
    this->faces[2] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),3);
    this->faces[3] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),4);
    this->faces[4] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),5);
    this->faces[5] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),6);
}

Voxel::Voxel(Vector3 coordinates, Material material){
    this->faces[0] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),1);
    this->faces[1] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),2);
    this->faces[2] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),3);
    this->faces[3] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),4);
    this->faces[4] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),5);
    this->faces[5] = VoxelMath::getVoxelFaces(coordinates, this->getSize(),6);

    this->material = material;
}

Face Voxel::getFaceByNum(int num){
    return this->faces[num];
}

void Voxel::setMaterial(Material material){
    this->material = material;
}

Material Voxel::getMaterial(){
    return this->material;
}

void Voxel::setPosition(Vector3 pos){
    this->position = pos;
}

Vector3 Voxel::getPosition(){
    return this->position;
}