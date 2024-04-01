#ifndef MATERIAL_H
#define MATERIAL_H
#include "main.h"

class Material
{
private:
	Color color;
	float transparency;
	float mass;
	float hardness;
public:
	Material();
	Material(Color);
	Material(Color,float transparency);
	Material(Color,float mass);
	Material(Color,float transparency, float mass);
	Material(Color,float transparency, float mass, float hardness);
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