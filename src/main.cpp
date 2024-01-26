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
int arr[1000][1000][200] = {0};//curPos = (Vector3){0,0,0};
Ray ray[960][540] = { 0 };  
int buffer[960][540] = {0};
int w = 960, h = 540;
Vector2 draws[7];
//Vector3 dots3D[8] = {0};
Vector3 cubes[8];
Vector3 v1 = {0}, v2 = {0};

//Vector2 GetWorldToScreen = {0};
static void UpdateDrawFrame(void);

int getSign(int a){
    if (a < 0)return -1;
    else return 1;
}

bool onScreen(Vector3 dot3D){
    Vector3 v1 = camera.position;
    Vector3 v2 = camera.target;
    Vector3 v12 = (Vector3){camera.target.x - camera.position.x,camera.target.y - camera.position.y,camera.target.z - camera.position.z};
    Vector3 v1d = (Vector3){dot3D.x - camera.position.x,dot3D.y - camera.position.y,dot3D.z - camera.position.z};
    float ang = acos((float)(v12.x*v1d.x + v12.y*v1d.y + v12.z*v1d.z)/((float)sqrt(v12.x*v12.x + v12.y*v12.y + v12.z*v12.z) * (float)sqrt(v1d.x*v1d.x + v1d.y*v1d.y + v1d.z*v1d.z)))*180/3.1415;
    if (ang <= 60)return true;
    else return false;
}

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
    DrawLine(dots2D[0].x, dots2D[0].y,dots2D[2].x, dots2D[2].y,RED);//000-010
    DrawLine(dots2D[0].x, dots2D[0].y,dots2D[4].x, dots2D[4].y,RED);//000-100
    DrawLine(dots2D[0].x, dots2D[0].y,dots2D[1].x, dots2D[1].y,RED);//000-001
    DrawLine(dots2D[4].x, dots2D[4].y,dots2D[6].x, dots2D[6].y,RED);//100-110
    DrawLine(dots2D[4].x, dots2D[4].y,dots2D[5].x, dots2D[5].y,RED);//100-101
    DrawLine(dots2D[2].x, dots2D[2].y,dots2D[6].x, dots2D[6].y,RED);//010-110
    DrawLine(dots2D[2].x, dots2D[2].y,dots2D[3].x, dots2D[3].y,RED);//010-011
    DrawLine(dots2D[1].x, dots2D[1].y,dots2D[3].x, dots2D[3].y,RED);//001-011
    DrawLine(dots2D[1].x, dots2D[1].y,dots2D[5].x, dots2D[5].y,RED);//001-101
    DrawLine(dots2D[5].x, dots2D[5].y,dots2D[7].x, dots2D[7].y,RED);//101-111
    DrawLine(dots2D[3].x, dots2D[3].y,dots2D[7].x, dots2D[7].y,RED);//011-111
    DrawLine(dots2D[6].x, dots2D[6].y,dots2D[7].x, dots2D[7].y,RED);//110-111
    }
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
        }
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
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
   // Vector3 v1 = camera.position;
   // Vector3 v2 = camera.target;
   // Vector3 v12 = (Vector3){camera.target.x - camera.position.x,camera.target.y - camera.position.y,camera.target.z - camera.position.z};
   // Vector3 v1d = (Vector3){dot3D.x - camera.position.x,dot3D.y - camera.position.y,camera.target.z - camera.position.z};
    //float ang = acos((float)(v12.x*v1d.x + v12.y*v1d.y + v12.z*v1d.z)/((float)sqrt(v12.x*v12.x + v12.y*v12.y + v12.z*v12.z) * (float)sqrt(v1d.x*v1d.x + v1d.y*v1d.y + v1d.z*v1d.z)))*180/3.1415;
    }
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
            DrawRay(ray[0][0], BLACK);
            DrawLine3D(v1,v2, BLACK);
            
            //DrawSphere((Vector3){x, y, z},1,RED);  
            //DrawSphereWires((Vector3){x, y, z},1.05,25,25,BLACK);  
            DrawGrid(10, 1.0f);
        EndMode3D();
        
        for (i = 0; i < 100; i++){
            for (j = 0; j < 100; j++){
                for (k = 0; k < 100; k++){
                    if (arr[i][k][j] == 1)
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