#ifndef VOXEL_H
#define VOXEL_H

#include "Face.h"
#include "Mater.h"
#include "../math/voxelMath.h"

class Voxel: public Face
{
private:
	Face faces[6];
	Mater material;
	Vector3 position;
	bool isEmpty = true;
public:
	Voxel();
	Voxel(Vector3);
	Voxel(Vector3, Mater);
	//
	Face getFaceByNum(int);
	//
	void setMater(Mater);
	Mater getMater();
	//
	void setPosition(Vector3);
	Vector3 getPosition();

	void SetEmpty(bool is);
	bool isEmptyB();
};


#endif // VOXEL_H