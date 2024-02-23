#include "macroblock.h"

Macroblock::Macroblock(Voxel vx){
    this->type = vx;
    this->size = vx.getSize() * this->div;
}

void Macroblock::setType(Voxel vx){
    this->type = vx;
    this->coordinates = vx.getCoordinates();
}

Voxel Macroblock::getType(){
    return this->type;
}

void Macroblock::setDiv(int div){
    this->div = div;
}

int Macroblock::getDiv(){
    return this->div;
}

float Macroblock::getSize(){
    return this->size;
}

Vector3 Macroblock::getCoordinates(){
    return this->coordinates;
}