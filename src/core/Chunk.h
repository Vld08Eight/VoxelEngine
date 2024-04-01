#ifndef CHUNK_H
#define CHUNK_H

#include "main.h"
#include "Macroblock.h"

class Chunk: public Macroblock
{
private:
	Macroblock** data;
	int size;
	Vector3 position;
public:
	Chunk();
	Chunk(int,int);
	Chunk(int,int,Vector3);
	Chunk(int,int,Material, Vector3);
	Chunk(int,Macroblock**, Vector3);
	//
	void setMacroblockByIndex(int,int,int,Material);
	void setMacroblockByIndex(int,int,int,Macroblock);
	void setMacroblockByIndex(Vector3,Material);
	void setMacroblockByIndex(Vector3,Macroblock);
	//
	Macroblock getMacroblockByIndex(int,int,int);
	Macroblock getMacroblockByIndex(Vector3);
	//
	void setPosition(Vector3);
	Vector3 getPosition();
	//
	int getSize();
};




#endif // CHUNK_H