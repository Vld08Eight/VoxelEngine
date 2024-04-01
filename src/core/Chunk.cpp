#include "Chunk.h"

Chunk::Chunk(){}

Chunk::Chunk(int size, int macroSize, Vector3 position){
    this->size = size;
    this->position = position;
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = Macroblock(macroSize);
            }
        }
    }
}

Chunk::Chunk(int size, int macroSize,Material material, Vector3 position){
    this->size = size;
    this->position = position;
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = Macroblock(macroSize, material, (Vector3){i,j,k});
            }
        }
    }
}

Chunk::Chunk(int size, Macroblock** macroblock, Vector3 position){
    this->size = size;
    this->position = position;
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = macroblock[i][j * this->size + k];
            }
        }
    }
}

Macroblock Chunk::getMacroblockByIndex(int i,int j,int k){
    return this->data[i][j * this->size + k];
}

Macroblock Chunk::getMacroblockByIndex(Vector3 position){
    return this->data[(int)position.x][(int)position.y * this->size + (int)position.z];
}

void Chunk::setPosition(Vector3 position){
    this->position = position;
}

Vector3 Chunk::getPosition(){
    return this->position;
}

int Chunk::getSize(){
    return this->size;  
}