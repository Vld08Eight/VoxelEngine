#include "voxelRender.h"

void VoxelRender::DrawFace(Face face, Camera camera){
    Vector3* dots3D = face.getFaceDots();
    bool isOnScreen;
    for (int i = 0; i < 4; i++){
        if (!VoxelMath::onScreen(camera,dots3D[i])){
            isOnScreen = false;
        }
    }
    if (isOnScreen){
        Vector2 dots2D[4] = {GetWorldToScreen(dots3D[0],camera),
                            GetWorldToScreen(dots3D[1],camera),
                            GetWorldToScreen(dots3D[2],camera),
                            GetWorldToScreen(dots3D[3],camera)};

        DrawLine(dots2D[0].x, dots2D[0].y,dots2D[1].x, dots2D[1].y,RED);
        DrawLine(dots2D[1].x, dots2D[1].y,dots2D[2].x, dots2D[2].y,RED);
        DrawLine(dots2D[2].x, dots2D[2].y,dots2D[3].x, dots2D[3].y,RED);
        DrawLine(dots2D[3].x, dots2D[3].y,dots2D[1].x, dots2D[1].y,RED);
    }
}