#include "Macroblock.h"

Macroblock::Macroblock(){}

Macroblock::Macroblock(int size){
    this->size = size;
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = Voxel((Vector3){i,j,k});
            }
        }
    }
}

Macroblock::Macroblock(int size, Vector3 position){
    this->size = size;
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = Voxel((Vector3){i,j,k});
            }
        }
    }
    this->position = position;
}

Macroblock::Macroblock(int size, Material material, Vector3 position){
    this->size = size;
    this->material = material;
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = Voxel((Vector3){i,j,k}, this->material);
            }
        }
    }
    this->position = position;
}

Macroblock::Macroblock(int size, Voxel** voxels, Vector3 position){
    this->size = size;
    
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = voxels[i][j * this->size + k];
            }
        }
    }
    this->position = position;
}


void Macroblock::setVoxelByIndex(int i,int j,int k,Material material){
    this->data[i][j * this->size + k] = Voxel((Vector3){i,j,k}, material);
}

void Macroblock::setVoxelByIndex(int i,int j,int k,Voxel voxel){
    this->data[i][j * this->size + k] = voxel;
}

void Macroblock::setVoxelByIndex(Vector3 position,Material material){
    this->data[(int)position.x][(int)position.y * this->size + (int)position.z] = Voxel(position, material);
}

void Macroblock::setVoxelByIndex(Vector3 position,Voxel voxel){
    this->data[(int)position.x][(int)position.y * this->size + (int)position.z] = Voxel(position, voxel.getMaterial());
}

Voxel Macroblock::getVoxelByIndex(int i,int j,int k){
    return this->data[i][j * this->size + k];
}

Voxel Macroblock::getVoxelByIndex(Vector3 position){
    return this->data[(int)position.x][(int)position.y * this->size + (int)position.z];
}

void Macroblock::setPosition(Vector3 position){
    this->position = position;
}

Vector3 Macroblock::getPosition(){
    return this->position;
}

int Macroblock::getSize(){
    return this->size;
}