#include "voxel.h"
//dont forget derive camera from scene
void Voxel::drawVoxelWires(Vector3 dots3D[], Color color){
    bool draw = true;
    for (int i = 0; i < 8; i++){
        if (!onScreen(dots3D[i])){
            draw = false;
            break;
        }
    }
    if (draw){
    int h = GetScreenHeight(), w = GetScreenWidth();
    Vector2 dots2D[8] = {GetWorldToScreen(dots3D[0], camera),
    GetWorldToScreen(dots3D[1], camera),
    GetWorldToScreen(dots3D[2], camera),
    GetWorldToScreen(dots3D[3], camera),
    GetWorldToScreen(dots3D[4], camera),
    GetWorldToScreen(dots3D[5], camera),
    GetWorldToScreen(dots3D[6], camera),
    GetWorldToScreen(dots3D[7], camera)};

    if (dots2D[0].x <= w && dots2D[0].y <= h &&
    dots2D[1].x <= w && dots2D[1].y <= h &&
    dots2D[2].x <= w && dots2D[2].y <= h &&
    dots2D[3].x <= w && dots2D[3].y <= h && 
    dots2D[4].x <= w && dots2D[4].y <= h && 
    dots2D[5].x <= w && dots2D[5].y <= h &&
    dots2D[6].x <= w && dots2D[6].y <= h && 
    dots2D[7].x <= w && dots2D[7].y <= h){
    DrawLine(dots2D[0].x, dots2D[0].y,dots2D[2].x, dots2D[2].y,color);//000-010
    DrawLine(dots2D[0].x, dots2D[0].y,dots2D[4].x, dots2D[4].y,color);//000-100
    DrawLine(dots2D[0].x, dots2D[0].y,dots2D[1].x, dots2D[1].y,color);//000-001
    DrawLine(dots2D[4].x, dots2D[4].y,dots2D[6].x, dots2D[6].y,color);//100-110
    DrawLine(dots2D[4].x, dots2D[4].y,dots2D[5].x, dots2D[5].y,color);//100-101
    DrawLine(dots2D[2].x, dots2D[2].y,dots2D[6].x, dots2D[6].y,color);//010-110
    DrawLine(dots2D[2].x, dots2D[2].y,dots2D[3].x, dots2D[3].y,color);//010-011
    DrawLine(dots2D[1].x, dots2D[1].y,dots2D[3].x, dots2D[3].y,color);//001-011
    DrawLine(dots2D[1].x, dots2D[1].y,dots2D[5].x, dots2D[5].y,color);//001-101
    DrawLine(dots2D[5].x, dots2D[5].y,dots2D[7].x, dots2D[7].y,color);//101-111
    DrawLine(dots2D[3].x, dots2D[3].y,dots2D[7].x, dots2D[7].y,color);//011-111
    DrawLine(dots2D[6].x, dots2D[6].y,dots2D[7].x, dots2D[7].y,color);//110-111
    }
    }
}

bool Voxel::onScreen(Vector3 dot3D){
    Vector3 v1 = camera.position;
    Vector3 v2 = camera.target;
    Vector3 v12 = (Vector3){camera.target.x - camera.position.x,camera.target.y - camera.position.y,camera.target.z - camera.position.z};
    Vector3 v1d = (Vector3){dot3D.x - camera.position.x,dot3D.y - camera.position.y,dot3D.z - camera.position.z};
    float ang = acos((float)(v12.x*v1d.x + v12.y*v1d.y + v12.z*v1d.z)/((float)sqrt(v12.x*v12.x + v12.y*v12.y + v12.z*v12.z) * (float)sqrt(v1d.x*v1d.x + v1d.y*v1d.y + v1d.z*v1d.z)))*180/3.1415;
    if (ang <= 60)return true;
    else return false;
}

Vector3* Voxel::getDots(int x, int y, int z){
    float fx = x, fy = y, fz = z;
    fx *= cubeSize.x;
    fy *= cubeSize.y;
    fz *= cubeSize.z;
    Vector3* dots3D = new Vector3[8];
    dots3D[0] = (Vector3){fx - ((cubeSize.x)/2),fy - ((cubeSize.x)/2), fz - ((cubeSize.x)/2)};//000 0
    dots3D[1] = (Vector3){fx - ((cubeSize.x)/2),fy - ((cubeSize.x)/2), fz + ((cubeSize.x)/2)};//001 1
    dots3D[2] = (Vector3){fx - ((cubeSize.x)/2),fy + ((cubeSize.x)/2), fz - ((cubeSize.x)/2)};//010 2
    dots3D[3] = (Vector3){fx - ((cubeSize.x)/2),fy + ((cubeSize.x)/2), fz + ((cubeSize.x)/2)};//011 3
    dots3D[4] = (Vector3){fx + ((cubeSize.x)/2),fy - ((cubeSize.x)/2), fz - ((cubeSize.x)/2)};//100 4
    dots3D[5] = (Vector3){fx + ((cubeSize.x)/2),fy - ((cubeSize.x)/2), fz + ((cubeSize.x)/2)};//101 5
    dots3D[6] = (Vector3){fx + ((cubeSize.x)/2),fy + ((cubeSize.x)/2), fz - ((cubeSize.x)/2)};//110 6
    dots3D[7] = (Vector3){fx + ((cubeSize.x)/2),fy + ((cubeSize.x)/2), fz + ((cubeSize.x)/2)};//111 7
    return dots3D;
}