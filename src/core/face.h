#ifndef FACE_H
#define FACE_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>

class Face
{


private:
	float size;
	Vector3 coordinates[4];
	Color color;
public:
	Face();
	Face(Vector3 coordinates[4]);
	Face(Vector3 coordinates[4], Color);
	//
	void setSize(float);
	float getSize();
	//
	void setColor(Color);
	Color getColor();
	//
	Vector3* getCoordinates();
	
};

#endif // FACE_H