#ifndef WORLD_H
#define WORLD_H

#include "Chunk.h"

class World: public Chunk
{
private:
	Chunk** data;
	int size;
public:
	Camera camera = { 0 };
	World();
	World(int);
	World(int,Chunk**);
	//
	void setChunkByIndex(int,int,int,int,int,Mater);
	void setChunkByIndex(int,int,int,int,int,Macroblock);
	void setChunkByIndex(Vector3,int,int,Mater);
	void setChunkByIndex(Vector3,Macroblock);
	//
	Chunk getChunkByIndex(int,int,int);
	Chunk getChunkByIndex(Vector3);
	//
	int getSize();
};




#endif // WORLD_H