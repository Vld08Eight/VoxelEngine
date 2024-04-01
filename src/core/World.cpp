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
    this->data = new Chunk*[this->size];
}

World::World(int size, Chunk** chunks){
    this->camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->camera.fovy = 60.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    std::cout << "init world complete" << std::endl;
    this->size = size;
    this->data = new Chunk*[this->size];
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < this->size; j++){
            for (int k = 0; k < this->size; k++){
                this->data[i][j * this->size + k] = chunks[i][j * this->size + k];
            }
        }
    }
}