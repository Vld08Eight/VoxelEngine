#include "World.h"

World::World(){

}

World::World(int size){
    this->camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->camera.fovy = 60.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    std::cout << "init world complete" << std::endl;
    this->size = size;
    this->data = new Chunk*[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = new Chunk[size * size];
    }
}

World::World(int size, Chunk** chunks){
    this->camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->camera.fovy = 60.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    std::cout << "init world complete" << std::endl;
    this->size = size;
    this->data = new Chunk*[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = new Chunk[size * size];
    }
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = chunks[i][j * this->size + k];
            }
        }
    }
}

Chunk World::getChunkByIndex(int i, int j, int k){
    return this->data[i][j * this->size + k];
}

Chunk World::getChunkByIndex(Vector3 position){
    return this->data[(int)position.x][(int)position.y * this->size + (int)position.z];
}

void World::setChunkByIndex(int chunkSize, int voxelSize, int i,int j,int k,Mater material){
    this->data[i][j * this->size + k] = Chunk(chunkSize, voxelSize, material, (Vector3){i,j,k});
}
void World::setChunkByIndex(int chunkSize,int voxelSize,int i,int j, int k,Macroblock macroblock){
    this->data[i][j * this->size + k] = Chunk(chunkSize, voxelSize, macroblock.getMater(), (Vector3){i,j,k});
}
void World::setChunkByIndex(Vector3 position,int chunkSize,int voxelSize,Mater material){
    this->data[(int)position.x][(int)position.y * this->size + (int)position.z] = Chunk(chunkSize, voxelSize, material, position);
}
void World::setChunkByIndex(Vector3 position,Macroblock macroblock){
    this->data[(int)position.x][(int)position.y * this->size + (int)position.z] = Chunk(size, size, macroblock.getMater(), position);
}

int World::getSize(){
    return this->size;
}