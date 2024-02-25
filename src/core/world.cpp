#include "world.h"

World::World(int size){
    this->size = size;
    this->worldArr = new Voxel*[size];
    for (int i = 0; i < size; i++) {
        this->worldArr[i] = new Voxel[size * size];
    }
    this->camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->camera.fovy = 60.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    std::cout << "init camera complete" << std::endl;
};


void World::setVoxelByIndex(int i, int j, int k, Color color) {
    this->worldArr[i][j * this->size + k] = Voxel((Vector3){(float)i,(float)j,(float)k}, color);
}

Voxel World::getVoxelByIndex(int i, int j, int k) {
    return this->worldArr[i][j * this->size + k];
}

int World::getSize(){
    return this->size;
}