#include "macroblock.h"

Macroblock::Macroblock(Voxel vx){
    this->type = vx;
    this->size = vx.getCubeSize() * this->div;
}

void Macroblock::setType(Voxel vx){
    this->type = vx;
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