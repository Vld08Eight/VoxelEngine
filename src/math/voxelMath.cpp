#include "voxelMath.h"


bool VoxelMath::onScreen(Camera camera, Vector3 dot3D){
    Vector3 v1 = camera.position;
    Vector3 v2 = camera.target;
    Vector3 v12 = (Vector3){camera.target.x - camera.position.x,camera.target.y - camera.position.y,camera.target.z - camera.position.z};
    Vector3 v1d = (Vector3){dot3D.x - camera.position.x,dot3D.y - camera.position.y,dot3D.z - camera.position.z};
    float ang = acos((float)(v12.x*v1d.x + v12.y*v1d.y + v12.z*v1d.z)/((float)sqrt(v12.x*v12.x + v12.y*v12.y + v12.z*v12.z) * (float)sqrt(v1d.x*v1d.x + v1d.y*v1d.y + v1d.z*v1d.z)))*180/3.1415;
    if (ang <= 60)return true;
    else return false;
}

float VoxelMath::getVec3Distance(Vector3 vec1, Vector3 vec2){
    return sqrt(pow(vec1.x - vec2.x,2)+pow(vec1.y - vec2.y,2)+pow(vec1.z - vec2.z,2));
}

Face VoxelMath::getVoxelFaces(Vector3 coordinates, float size, int id){
    Face face;

    Vector3 dots[4];

    float halfSize = size/2;
    coordinates = VoxelMath::arrToWorld(coordinates, size);
    switch (id)
    {
    case 1:
    dots[0] = (Vector3){coordinates.x+halfSize, coordinates.y-halfSize, coordinates.z+halfSize};//1002
    dots[1] = (Vector3){coordinates.x-halfSize, coordinates.y-halfSize, coordinates.z+halfSize};
    dots[3] = (Vector3){coordinates.x+halfSize, coordinates.y-halfSize, coordinates.z-halfSize};
    dots[2] = (Vector3){coordinates.x-halfSize, coordinates.y-halfSize, coordinates.z-halfSize};//4003
    face = Face(dots);
    break;
    case 2:
    dots[2] = (Vector3){coordinates.x+halfSize, coordinates.y-halfSize, coordinates.z+halfSize};//1002
    dots[1] = (Vector3){coordinates.x+halfSize, coordinates.y+halfSize, coordinates.z+halfSize};
    dots[3] = (Vector3){coordinates.x+halfSize, coordinates.y-halfSize, coordinates.z-halfSize};
    dots[0] = (Vector3){coordinates.x+halfSize, coordinates.y+halfSize, coordinates.z-halfSize};//4003
    face = Face(dots);
    break;
    case 3:
    dots[2] = (Vector3){coordinates.x+halfSize, coordinates.y+halfSize, coordinates.z+halfSize};//1002
    dots[1] = (Vector3){coordinates.x-halfSize, coordinates.y+halfSize, coordinates.z+halfSize};
    dots[3] = (Vector3){coordinates.x+halfSize, coordinates.y+halfSize, coordinates.z-halfSize};
    dots[0] = (Vector3){coordinates.x-halfSize, coordinates.y+halfSize, coordinates.z-halfSize};//4003
    face = Face(dots);
    break;
    case 4:
    dots[2] = (Vector3){coordinates.x-halfSize, coordinates.y+halfSize, coordinates.z+halfSize};//1002
    dots[1] = (Vector3){coordinates.x-halfSize, coordinates.y-halfSize, coordinates.z+halfSize};
    dots[3] = (Vector3){coordinates.x-halfSize, coordinates.y+halfSize, coordinates.z-halfSize};
    dots[0] = (Vector3){coordinates.x-halfSize, coordinates.y-halfSize, coordinates.z-halfSize};//4003
    face = Face(dots);
    break;
    case 5:
    dots[2] = (Vector3){coordinates.x+halfSize, coordinates.y+halfSize, coordinates.z+halfSize};//1002
    dots[1] = (Vector3){coordinates.x+halfSize, coordinates.y-halfSize, coordinates.z+halfSize};
    dots[3] = (Vector3){coordinates.x-halfSize, coordinates.y+halfSize, coordinates.z+halfSize};
    dots[0] = (Vector3){coordinates.x-halfSize, coordinates.y-halfSize, coordinates.z+halfSize};//4003
    face = Face(dots);
    break;
    case 6:
    dots[0] = (Vector3){coordinates.x+halfSize, coordinates.y+halfSize, coordinates.z-halfSize};//1002
    dots[1] = (Vector3){coordinates.x+halfSize, coordinates.y-halfSize, coordinates.z-halfSize};
    dots[3] = (Vector3){coordinates.x-halfSize, coordinates.y+halfSize, coordinates.z-halfSize};
    dots[2] = (Vector3){coordinates.x-halfSize, coordinates.y-halfSize, coordinates.z-halfSize};//4003
    face = Face(dots);
    break;
    default:
        break;
    }
    return face;
}

Vector3 VoxelMath::arrToWorld(Vector3 coordinates, float size){
    return (Vector3){coordinates.x*size, coordinates.y*size, coordinates.z*size};
}

Vector3 VoxelMath::vec3Multiply(Vector3 a, Vector3 b){
    return (Vector3){a.y*b.z-a.z*b.y, a.x*b.z-a.z*b.x, a.x*b.y-a.y*b.x};
}

Vector3 VoxelMath::getfaceNormal(Face face){
    Vector3* dots = face.getFaceDots();
    Vector3 p1 = VoxelMath::arrToWorld(dots[0], face.getSize());
    Vector3 p2 = VoxelMath::arrToWorld(dots[1], face.getSize());
    Vector3 p3 = VoxelMath::arrToWorld(dots[2], face.getSize());
    return VoxelMath::vec3Multiply((Vector3){p2.x-p1.x,p2.y-p1.y,p2.z-p1.z},(Vector3){p3.x-p1.x,p3.y-p1.y,p3.z-p1.z});
}
