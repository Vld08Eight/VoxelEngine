#include "Mater.h"

Mater::Mater(){
    this->color = GREEN;
    this->mass = 1;
    this->hardness = 1;
    this->transparency = 0;
}

Mater::Mater(Color color){
    this->color = color;
    this->mass = 1;
    this->hardness = 1;
    this->transparency = 0;
}

Mater::Mater(Color color, float mass){
    this->color = color;
    this->mass = mass;
    this->hardness = 1;
    this->transparency = 0;
}

Mater::Mater(Color color,float transparency, float mass){
    this->color = color;
    this->mass = mass;
    this->hardness = 1;
    this->transparency = transparency;
}

Mater::Mater(Color color,float transparency, float mass, float hardness){
    this->color = color;
    this->mass = mass;
    this->hardness = hardness;
    this->transparency = transparency;
}

void Mater::setColor(Color color){
    this->color = color;
}

Color Mater::getColor(){
    return this->color;
}

void Mater::setTransparency(float transparency){
    this->transparency = transparency;
}
	
float Mater::getTransparency(){
    return this->transparency;
}
	
void Mater::setMass(float mass){
    this->mass = mass;
}
	
float Mater::getMass(){
    return this->mass;
}
	
void Mater::setHardness(float hardness){
    this->hardness = hardness;
}
	
float Mater::getHardness(){
    return this->hardness;
}