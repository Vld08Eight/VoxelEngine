#include "Face.h"

Face::Face(){}

Face::Face(Vector3 coordinates[4]){
    for(int i = 0; i < 4; i++)this->coordinates[i] = coordinates[i];
}

Face::Face(Vector3 coordinates[4], Color color){
    for(int i = 0; i < 4; i++)this->coordinates[i] = coordinates[i];
    this->color = color;
}

void Face::setSize(float size){
    this->size = size;
}

float Face::getSize(){
    return this->size;
}

void Face::setColor(Color color){
    this->color = color;
}

Color Face::getColor(){
    return this->color;
}

Vector3* Face::getCoordinates(){
    return this->coordinates;
}