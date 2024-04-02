#ifndef MACROBLOCK_H
#define MACROBLOCK_H

#include "Voxel.h"

class Macroblock: public Voxel
{
private:
	Voxel** data;
	int size;
	Vector3 position;
	Mater material;
public:
	Macroblock();
	Macroblock(int);
	Macroblock(int, Vector3);
	Macroblock(int,Vector3,Voxel);
	Macroblock(int, Mater, Vector3);
	Macroblock(int, Voxel**, Vector3);
	//
	void setVoxelByIndex(int,int,int,Mater);
	void setVoxelByIndex(int,int,int,Voxel);
	void setVoxelByIndex(Vector3,Mater);
	void setVoxelByIndex(Vector3,Voxel);
	//
	Voxel getVoxelByIndex(int,int,int);
	Voxel getVoxelByIndex(Vector3);
	//
	void setPosition(Vector3);
	Vector3 getPosition();
	//
	int getSize();
};




#endif // MACROBLOCK_H