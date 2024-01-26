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
int arr[10][10][20] = {0};//curPos = (Vector3){0,0,0};
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

// Функция для генерации случайного шума Перлина в 2D
Vector3* getDots(int x, int y, int z){
    Vector3* dots3D = new Vector3[8];
    dots3D[0] = (Vector3){x - ((cubeSize.x)/2),y - ((cubeSize.x)/2), z - ((cubeSize.x)/2)};
    dots3D[1] = (Vector3){x + ((cubeSize.x)/2),y - ((cubeSize.x)/2), z - ((cubeSize.x)/2)};
    dots3D[2] = (Vector3){x - ((cubeSize.x)/2),y + ((cubeSize.x)/2), z - ((cubeSize.x)/2)};
    dots3D[3] = (Vector3){x - ((cubeSize.x)/2),y - ((cubeSize.x)/2), z + ((cubeSize.x)/2)};
    dots3D[4] = (Vector3){x + ((cubeSize.x)/2),y + ((cubeSize.x)/2), z - ((cubeSize.x)/2)};
    dots3D[5] = (Vector3){x + ((cubeSize.x)/2),y - ((cubeSize.x)/2), z + ((cubeSize.x)/2)};
    dots3D[6] = (Vector3){x - ((cubeSize.x)/2),y + ((cubeSize.x)/2), z + ((cubeSize.x)/2)};
    dots3D[7] = (Vector3){x + ((cubeSize.x)/2),y + ((cubeSize.x)/2), z + ((cubeSize.x)/2)};
    return dots3D;
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
    Vector3 *Dots3D = getDots(1,1,1);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        //x = camera.target.x;
        //y = camera.target.y;
        //z = camera.target.z;
        for (i = 0; i <= 1; i++){
            for (j = 0; j <= 1; j++){
                for (k = 0; k <= 1; k++){
                    std::cout << GetWorldToScreen(Dots3D[s], camera).x << " " << GetWorldToScreen(Dots3D[s], camera).y << std::endl;
                    s++;
                }
            }
        }
    }
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
            
            
            
            //DrawSphere((Vector3){x, y, z},1,RED);  
            //DrawSphereWires((Vector3){x, y, z},1.05,25,25,BLACK);  
            DrawGrid(10, 1.0f);
        EndMode3D();
        
        
        s = 0;
        for (i = 0; i <= 1; i++){
            for (j = 0; j <= 1; j++){
                for (k = 0; k <= 1; k++){
                    
                    DrawRectangle(GetWorldToScreen(Dots3D[s], camera).x, GetWorldToScreen(Dots3D[s], camera).y,2,2,RED);
                    
                    s++;
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