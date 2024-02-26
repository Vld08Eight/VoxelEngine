#ifndef VOXELRENDER_H
#define VOXELRENDER_H

#include "raylib.h"
#include "math.h"
#include <iostream>
#include "../core/voxel.h"
#include "../core/world.h"
#include "../math/voxelMath.h"
#include "../core/face.h"
#include <vector>
#include <algorithm>

class VoxelRender{

    
public:
    static void DrawFaceWires(Face, Camera);
    static void DrawFace(Face, Camera, Color);
    static void DrawVoxelWires(Voxel, Camera);
    static void DrawVoxelFaces(Voxel, Camera, Color, World);
    static std::vector<Voxel> getRenderArray(Camera, World);
    static std::vector<Voxel> sortRenderArray(std::vector<Voxel>, std::vector<float>);
    static void DrawVoxelsVec(std::vector<Voxel>, Camera, World);
    static std::vector<Face> sortFacesArray(std::vector<Face>, std::vector<float>);
    static Voxel isSelected(std::vector<Voxel>, Camera);
};

#endif // VOXELRENDER_H