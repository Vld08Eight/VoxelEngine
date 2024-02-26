#include "worldEdit.h"


void WorldEdit::setVoxel(World world, Voxel voxel, Camera camera){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        int face = VoxelRender::isSelectedFace(voxel, camera);
        Vector3 coord = voxel.getCoordinates();
        std::cout << coord.x << " " << coord.y << " " << coord.z << " " << face << std::endl;
        switch (face)
        {
        case 0:
            world.setVoxelByIndex(coord.x,coord.y-1,coord.z,voxel.getColor());
            break;
        case 1:
            world.setVoxelByIndex(coord.x+1,coord.y,coord.z,voxel.getColor());
            break;
        case 2:
            world.setVoxelByIndex(coord.x,coord.y+1,coord.z,voxel.getColor());
            break;
        case 3:
            world.setVoxelByIndex(coord.x-1,coord.y,coord.z,voxel.getColor());
            break;
        case 4:
            world.setVoxelByIndex(coord.x,coord.y,coord.z+1,voxel.getColor());
            break;
        case 5:
            world.setVoxelByIndex(coord.x,coord.y,coord.z-1,voxel.getColor());
            break;
        default:
            break;
        }
    }
}