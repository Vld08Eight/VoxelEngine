#ifndef VOXEL_H
#define VOXEL_H

#include "main.h"
#include "Face.h"
#include "Material.h"
#include "../math/voxelMath.h"

class Voxel: public Face
{
private:
	Face faces[6];
	Material material;
	Vector3 position;
	bool isEmpty = true;
public:
	Voxel();
	Voxel(Vector3);
	Voxel(Vector3, Material);
	//
	Face getFaceByNum(int);
	//
	void setMaterial(Material);
	Material getMaterial();
	//
	void setPosition(Vector3);
	Vector3 getPosition();
};


#endif // VOXEL_H