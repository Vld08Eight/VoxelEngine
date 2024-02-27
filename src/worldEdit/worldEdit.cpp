#include "worldEdit.h"


void WorldEdit::setVoxel(World world, Voxel voxel, Camera camera, Color color){
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector3 coord = voxel.getCoordinates();
        if (coord.x != -1){
        int face = VoxelRender::isSelectedFace(voxel, camera);
        std::cout << coord.x << " " << coord.y << " " << coord.z << " " << face << std::endl;
        switch (face)
        {
        case 0:
            world.setVoxelByIndex(coord.x,coord.y-1,coord.z,color);
            break;
        case 1:
            world.setVoxelByIndex(coord.x+1,coord.y,coord.z,color);
            break;
        case 2:
            world.setVoxelByIndex(coord.x,coord.y+1,coord.z,color);
            break;
        case 3:
            world.setVoxelByIndex(coord.x-1,coord.y,coord.z,color);
            break;
        case 4:
            world.setVoxelByIndex(coord.x,coord.y,coord.z+1,color);
            break;
        case 5:
            world.setVoxelByIndex(coord.x,coord.y,coord.z-1,color);
            break;
        default:
            break;
        }
    }
    }
}

void WorldEdit::removeVoxel(World world, Voxel voxel){
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
        Vector3 coord = voxel.getCoordinates();
        if (coord.x != -1){
        world.setEmptyByIndex(coord.x,coord.y,coord.z);
    }
    }
}