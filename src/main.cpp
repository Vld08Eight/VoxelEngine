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
int i,j,k,x,y,z;
int arr[10][10][20] = {0};//curPos = (Vector3){0,0,0};
Ray ray[960][540] = { 0 };  
int buffer[960][540] = {0};

static void UpdateDrawFrame(void);

float objectDistance(Vector3 vec1, Vector3 vec2){
    return sqrt(pow(vec1.x - vec2.x,2)+pow(vec1.y - vec2.y,2)+pow(vec1.z - vec2.z,2));
};
// Функция для генерации случайного шума Перлина в 2D
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
    
    std::vector<std::vector<double>> perlinNoise = generatePerlinNoise(10, 10);

    

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            arr[i][j][(int)((perlinNoise[i][j]+1)*5)] = 1;
            std::cout << arr[i][j][1] << " "; 
        }
        std::cout << std::endl;
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

    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
            
                
            
            
            for(i = 1; i< 960; i+=10){
                for(j = 1; j < 540; j+=5){
                    ray[i][j] = GetMouseRay((Vector2){i, j}, camera);
                    for(x = 0; x < 10; x++){
                        for(y = 0; y < 10; y++){
                            for(z = 0; z < 10; z++){
                                if (arr[x][y][z] == 1){
                                    //DrawCubeWires((Vector3){x,y,z},1,1,1,BLUE);
                                collision = GetRayCollisionBox(ray[i][j],
                                        (BoundingBox){(Vector3){ x - cubeSize.x/2, y - cubeSize.y/2, z - cubeSize.z/2 },
                                        (Vector3){ x + cubeSize.x/2, y + cubeSize.y/2, z + cubeSize.z/2 }});
                                if (collision.hit == true){
                                    buffer[i][j] = 1;
                                    //std::cout << 1;
                                }
                                }
                            }
                        }
                    }
                    //DrawRay(ray[i][j], RED);
                    
                }
            }    

            DrawGrid(10, 1.0f);
        EndMode3D();
        
        for (i = 1; i < 960; i++){
            for (j = 1; j < 540; j++){
                if(buffer[i][j] == 1){
                    DrawRectangle(i, j, 8, 2, RED);
                    buffer[i][j] = 0;
                    //std::cout << 2;
                }    
            }
        }
        //char p[10];
        //DrawText(itoa(kol, p, 10), 10, 40, 20, DARKGRAY);
        
        DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}