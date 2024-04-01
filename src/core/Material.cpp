#include "Material.h"

Material::Material(){
    this->color = GREEN;
    this->mass = 1;
    this->hardness = 1;
    this->transparency = 0;
}

Material::Material(Color color){
    this->color = color;
    this->mass = 1;
    this->hardness = 1;
    this->transparency = 0;
}

Material::Material(Color color, float mass){
    this->color = color;
    this->mass = mass;
    this->hardness = 1;
    this->transparency = 0;
}

Material::Material(Color color,float transparency, float mass){
    this->color = color;
    this->mass = mass;
    this->hardness = 1;
    this->transparency = transparency;
}

Material::Material(Color color,float transparency, float mass, float hardness){
    this->color = color;
    this->mass = mass;
    this->hardness = hardness;
    this->transparency = transparency;
}

void Material::setColor(Color color){
    this->color = color;
}

Color Material::getColor(){
    return this->color;
}

void Material::setTransparency(float transparency){
    this->transparency = transparency;
}
	
float Material::getTransparency(){
    return this->transparency;
}
	
void Material::setMass(float mass){
    this->mass = mass;
}
	
float Material::getMass(){
    return this->mass;
}
	
void Material::setHardness(float hardness){
    this->hardness = hardness;
}
	
float Material::getHardness(){
    return this->hardness;
}