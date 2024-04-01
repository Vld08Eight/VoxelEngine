#ifndef WORLD_H
#define WORLD_H

#include "main.h"
#include "Chunk.h"

class World: public Chunk
{
private:
	Chunk** data;
	int size;
public:
	Camera camera = { 0 };
	World();
	World(Material);
	World(Chunk**);
	//
	void setChunkByIndex(int,int,int,Material);
	void setChunkByIndex(int,int,int,Macroblock);
	void setChunkByIndex(Vector3,Material);
	void setChunkByIndex(Vector3,Macroblock);
	//
	Voxel getChunkByIndex(int,int,int);
	Voxel getChunkByIndex(Vector3);
	//
	int getSize();
};




#endif // WORLD_H