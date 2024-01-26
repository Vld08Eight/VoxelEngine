#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <string> 
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
Camera camera = { 0 };
Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };
Vector3 cubeSize = { 1.0f, 1.0f, 1.0f };
RayCollision collision = { 0 };
int i,j,k,s;
float x = 0,y = 0,z = 0;
int arr[100][100][200] = {0};//curPos = (Vector3){0,0,0};
Ray ray[960][540] = { 0 };  
int buffer[960][540] = {0};
int w = 960, h = 540;
Vector2 draws[7];
//Vector3 dots3D[8] = {0};
Vector3 cubes[8];


//Vector2 GetWorldToScreen = {0};
static void UpdateDrawFrame(void);

float objectDistance(Vector3 vec1, Vector3 vec2){
    return sqrt(pow(vec1.x - vec2.x,2)+pow(vec1.y - vec2.y,2)+pow(vec1.z - vec2.z,2));
};

std::vector<std::vector<double>> generatePerlinNoise(int x, int y) {
    // Создаем вектор для хранения шума
    std::vector<std::vector<double>> noise(x, std::vector<double>(y));

    // Задаем случайное семя для генератора
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    // Генерируем шум в каждой точке
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            noise[i][j] = dist(rng);
        }
    }

    return noise;
}

Vector3* getDots(int x, int y, int z){
    Vector3* dots3D = new Vector3[8];
    dots3D[0] = (Vector3){x - ((cubeSize.x)/2),y - ((cubeSize.x)/2), z - ((cubeSize.x)/2)};//000 0
    dots3D[1] = (Vector3){x - ((cubeSize.x)/2),y - ((cubeSize.x)/2), z + ((cubeSize.x)/2)};//001 1
    dots3D[2] = (Vector3){x - ((cubeSize.x)/2),y + ((cubeSize.x)/2), z - ((cubeSize.x)/2)};//010 2
    dots3D[3] = (Vector3){x - ((cubeSize.x)/2),y + ((cubeSize.x)/2), z + ((cubeSize.x)/2)};//011 3
    dots3D[4] = (Vector3){x + ((cubeSize.x)/2),y - ((cubeSize.x)/2), z - ((cubeSize.x)/2)};//100 4
    dots3D[5] = (Vector3){x + ((cubeSize.x)/2),y - ((cubeSize.x)/2), z + ((cubeSize.x)/2)};//101 5
    dots3D[6] = (Vector3){x + ((cubeSize.x)/2),y + ((cubeSize.x)/2), z - ((cubeSize.x)/2)};//110 6
    dots3D[7] = (Vector3){x + ((cubeSize.x)/2),y + ((cubeSize.x)/2), z + ((cubeSize.x)/2)};//111 7
    return dots3D;
}

void DrawCW(Vector3 dots3D[]){
    int h = GetScreenHeight(), w = GetScreenWidth();
    if (GetWorldToScreen(dots3D[0], camera).x <= w && GetWorldToScreen(dots3D[0], camera).y <= h &&
    GetWorldToScreen(dots3D[1], camera).x <= w && GetWorldToScreen(dots3D[1], camera).y <= h &&
    GetWorldToScreen(dots3D[2], camera).x <= w && GetWorldToScreen(dots3D[2], camera).y <= h &&
    GetWorldToScreen(dots3D[3], camera).x <= w && GetWorldToScreen(dots3D[3], camera).y <= h && 
    GetWorldToScreen(dots3D[4], camera).x <= w && GetWorldToScreen(dots3D[4], camera).y <= h && 
    GetWorldToScreen(dots3D[5], camera).x <= w && GetWorldToScreen(dots3D[5], camera).y <= h &&
    GetWorldToScreen(dots3D[6], camera).x <= w && GetWorldToScreen(dots3D[6], camera).y <= h && 
    GetWorldToScreen(dots3D[7], camera).x <= w && GetWorldToScreen(dots3D[7], camera).y <= h){
    DrawLine(GetWorldToScreen(dots3D[0], camera).x, GetWorldToScreen(dots3D[0], camera).y,GetWorldToScreen(dots3D[2], camera).x, GetWorldToScreen(dots3D[2], camera).y,RED);//000-010
    DrawLine(GetWorldToScreen(dots3D[0], camera).x, GetWorldToScreen(dots3D[0], camera).y,GetWorldToScreen(dots3D[4], camera).x, GetWorldToScreen(dots3D[4], camera).y,RED);//000-100
    DrawLine(GetWorldToScreen(dots3D[0], camera).x, GetWorldToScreen(dots3D[0], camera).y,GetWorldToScreen(dots3D[1], camera).x, GetWorldToScreen(dots3D[1], camera).y,RED);//000-001
    DrawLine(GetWorldToScreen(dots3D[4], camera).x, GetWorldToScreen(dots3D[4], camera).y,GetWorldToScreen(dots3D[6], camera).x, GetWorldToScreen(dots3D[6], camera).y,RED);//100-110
    DrawLine(GetWorldToScreen(dots3D[4], camera).x, GetWorldToScreen(dots3D[4], camera).y,GetWorldToScreen(dots3D[5], camera).x, GetWorldToScreen(dots3D[5], camera).y,RED);//100-101
    DrawLine(GetWorldToScreen(dots3D[2], camera).x, GetWorldToScreen(dots3D[2], camera).y,GetWorldToScreen(dots3D[6], camera).x, GetWorldToScreen(dots3D[6], camera).y,RED);//010-110
    DrawLine(GetWorldToScreen(dots3D[2], camera).x, GetWorldToScreen(dots3D[2], camera).y,GetWorldToScreen(dots3D[3], camera).x, GetWorldToScreen(dots3D[3], camera).y,RED);//010-011
    DrawLine(GetWorldToScreen(dots3D[1], camera).x, GetWorldToScreen(dots3D[1], camera).y,GetWorldToScreen(dots3D[3], camera).x, GetWorldToScreen(dots3D[3], camera).y,RED);//001-011
    DrawLine(GetWorldToScreen(dots3D[1], camera).x, GetWorldToScreen(dots3D[1], camera).y,GetWorldToScreen(dots3D[5], camera).x, GetWorldToScreen(dots3D[5], camera).y,RED);//001-101
    DrawLine(GetWorldToScreen(dots3D[5], camera).x, GetWorldToScreen(dots3D[5], camera).y,GetWorldToScreen(dots3D[7], camera).x, GetWorldToScreen(dots3D[7], camera).y,RED);//101-111
    DrawLine(GetWorldToScreen(dots3D[3], camera).x, GetWorldToScreen(dots3D[3], camera).y,GetWorldToScreen(dots3D[7], camera).x, GetWorldToScreen(dots3D[7], camera).y,RED);//011-111
    DrawLine(GetWorldToScreen(dots3D[6], camera).x, GetWorldToScreen(dots3D[6], camera).y,GetWorldToScreen(dots3D[7], camera).x, GetWorldToScreen(dots3D[7], camera).y,RED);//110-111
    }
}

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "raylib");
    
    camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    std::vector<std::vector<double>> perlinNoise = generatePerlinNoise(100, 100);



    for (i = 0; i < 100; i++){
        for (j = 0; j < 100; j++){
            arr[i][j][(int)((perlinNoise[i][j]+1)*5)] = 1;
            //std::cout << arr[i][j][1] << " "; 
        }
        //std::cout << std::endl;
    }

    DisableCursor();         
    SetTargetFPS(60); 

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


// Update and draw game frame
static void UpdateDrawFrame(void)
{
    UpdateCamera(&camera, CAMERA_FREE);
    //Vector3 *dots3d = getDots(1,1,1);
    
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
            
            
            
            //DrawSphere((Vector3){x, y, z},1,RED);  
            //DrawSphereWires((Vector3){x, y, z},1.05,25,25,BLACK);  
            DrawGrid(10, 1.0f);
        EndMode3D();
        
        for (i = 0; i < 100; i++){
            for (j = 0; j < 100; j++){
                for (k = 0; k < 100; k++){
                    if (arr[i][j][k] == 1)
                    DrawCW(getDots(i,j,k));
                }
            }
        }
        
        
        char p[10];
        DrawText("x", 5, 40, 30, DARKGRAY);
        DrawText(itoa(camera.position.x, p, 10), 30, 40, 30, DARKGRAY);
        DrawText("y", 5, 80, 30, DARKGRAY);
        DrawText(itoa(camera.position.y, p, 10), 30, 80, 30, DARKGRAY);
        
        DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}