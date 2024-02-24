#include "world.h"

World::World(){
    this->camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->camera.fovy = 60.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    std::cout << "init camera complete" << std::endl;
};

