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
    std::vector<Face> faces;
    std::vector<float> distances;
    for(int i = 0; i < 6; i++){
        faces.push_back(voxel.getFaceByNum(i));
        distances.push_back(VoxelMath::getVec3Distance(VoxelMath::getfaceNormal(faces[i]),camera.position));
    }
    faces = VoxelRender::sortFacesArray(faces,distances);
    for(int i = 0; i < 6; i++){//change faces normals
        VoxelRender::DrawFace(faces[i],camera,color);
    }
}

std::vector<Voxel> VoxelRender::getRenderArray(Camera camera, World worldArr){
    std::vector<Voxel> voxels;
    std::vector<float> distances;
    Voxel voxel;
    int size = worldArr.getSize();
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){ 
                voxel = worldArr.getVoxelByIndex(i,j,k);
                if(voxel.isEmpty() == false){
                    Vector3 voxWorld = VoxelMath::arrToWorld(voxel.getCoordinates(),voxel.getSize());
                    if (VoxelMath::onScreen(camera, voxWorld)){
                        voxels.push_back(voxel);
                        distances.push_back(VoxelMath::getVec3Distance(camera.position, voxWorld));
                    }
                }
            }
        }
    }
    return VoxelRender::sortRenderArray(voxels,distances);
}

bool compareVectors(const std::pair<float, Voxel>& lhs, const std::pair<float, Voxel>& rhs) {
    return lhs.first < rhs.first;
}

std::vector<Voxel> VoxelRender::sortRenderArray(std::vector<Voxel> voxels, std::vector<float> distances){
    std::vector<std::pair<float, Voxel>> pairs;
    for (size_t i = 0; i < distances.size(); ++i) {
        pairs.push_back(std::make_pair(distances[i], voxels[i]));
    }

    // Сортировка вектора пар с помощью алгоритма std::sort() и пользовательской функции сравнения
    std::sort(pairs.begin(), pairs.end(), compareVectors);

    // Обновление вектора vec2 с помощью отсортированного вектора пар
    std::vector<Voxel> sortedVec2;
    for (const auto& pair : pairs) {
        sortedVec2.push_back(pair.second);
    }
    return sortedVec2;

}

void VoxelRender::DrawVoxelsVec(std::vector<Voxel> voxels, Camera camera){
    int size = voxels.size();
    for(int i = 0; i < size; i++){
        VoxelRender::DrawVoxelFaces(voxels[i], camera, voxels[i].getColor());
    }
}

bool compareFacesVectors(const std::pair<float, Face>& lhs, const std::pair<float, Face>& rhs) {
    return lhs.first < rhs.first;
}

std::vector<Face> VoxelRender::sortFacesArray(std::vector<Face> voxels, std::vector<float> distances){
    std::vector<std::pair<float, Face>> pairs;
    for (size_t i = 0; i < distances.size(); ++i) {
        pairs.push_back(std::make_pair(distances[i], voxels[i]));
    }

    // Сортировка вектора пар с помощью алгоритма std::sort() и пользовательской функции сравнения
    std::sort(pairs.begin(), pairs.end(), compareFacesVectors);

    // Обновление вектора vec2 с помощью отсортированного вектора пар
    std::vector<Face> sortedVec2;
    for (const auto& pair : pairs) {
        sortedVec2.push_back(pair.second);
    }
    return sortedVec2;

}