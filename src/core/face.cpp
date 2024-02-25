#include "Face.h"

Face::Face(Vector3 coordinates[4]){
    for(int i = 0; i < 4; i++)this->coordinates[i] = coordinates[i];
}

float Face::getSize(){
    return this->size;
}

Vector3* Face::getFaceDots(){
    return this->coordinates;
}

Color Face::getColor(){
    return this->color;
}

void Face::setColor(Color color){
    this->color = color;
}