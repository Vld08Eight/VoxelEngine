#ifndef MATERIAL_H
#define MATERIAL_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>

class Mater
{
private:
	Color color;
	float transparency;
	float mass;
	float hardness;
public:
	Mater();
	Mater(Color);
	Mater(Color,float mass);
	Mater(Color,float transparency, float mass);
	Mater(Color,float transparency, float mass, float hardness);
	//
	void setColor(Color);
	Color getColor();
	//
	void setTransparency(float);
	float getTransparency();
	//
	void setMass(float);
	float getMass();
	//
	void setHardness(float);
	float getHardness();
	
};



#endif // MATERIAL_H