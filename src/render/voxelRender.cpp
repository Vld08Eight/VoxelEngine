#include "voxelRender.h"

void VoxelRender::DrawFaceWires(Face face, Camera camera){
    Vector3* dots3D = face.getFaceDots();
    bool isOnScreen = true;
    for (int i = 0; i < 4; i++){
        if (!VoxelMath::onScreen(camera,dots3D[i])){
            isOnScreen = false;
        }
    }
    if (isOnScreen == true){
        Vector2 dots2D[4] = {GetWorldToScreen(dots3D[0],camera),
                            GetWorldToScreen(dots3D[1],camera),
                            GetWorldToScreen(dots3D[2],camera),
                            GetWorldToScreen(dots3D[3],camera)};

        DrawLine(dots2D[0].x, dots2D[0].y,dots2D[1].x, dots2D[1].y,RED);
        DrawLine(dots2D[1].x, dots2D[1].y,dots2D[2].x, dots2D[2].y,RED);
        DrawLine(dots2D[2].x, dots2D[2].y,dots2D[3].x, dots2D[3].y,RED);
        DrawLine(dots2D[3].x, dots2D[3].y,dots2D[0].x, dots2D[0].y,RED);
    }
}

void VoxelRender::DrawFace(Face face,Camera camera, Color color){
    Vector3* dots3D = face.getFaceDots();
    bool isOnScreen = true;
    for (int i = 0; i < 4; i++){
        if (!VoxelMath::onScreen(camera,dots3D[i])){
            isOnScreen = false;
        }
    }
    if (isOnScreen == true){
        //Vector3 normal = Vector3Multiply(dots3D[0],dots3D[1]);
        Vector2 dots2D[4] = {GetWorldToScreen(dots3D[0],camera),
                            GetWorldToScreen(dots3D[1],camera),
                            GetWorldToScreen(dots3D[2],camera),
                            GetWorldToScreen(dots3D[3],camera)};

        DrawTriangle(dots2D[0],dots2D[1],dots2D[2],color);
        DrawTriangle(dots2D[2],dots2D[3],dots2D[0],color);
    }
}
//not optimize
void VoxelRender::DrawVoxelWires(Voxel voxel, Camera camera){
    for(int i = 0; i < 6; i++){
        VoxelRender::DrawFaceWires(voxel.getFaceByNum(i), camera);
    }
}

void VoxelRender::DrawVoxelFaces(Voxel voxel, Camera camera, Color color){
    for(int i = 0; i < 6; i++){
        VoxelRender::DrawFace(voxel.getFaceByNum(i), camera, color);
    }
}