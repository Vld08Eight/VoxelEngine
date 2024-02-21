#include "main.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int i,j,k,s;
int arr[500][500][500] = {0};

Voxel vx1;
Camera cam = vx1.getCamera();
static void UpdateDrawFrame(void);



float objectDistance(Vector3 vec1, Vector3 vec2){
    return sqrt(pow(vec1.x - vec2.x,2)+pow(vec1.y - vec2.y,2)+pow(vec1.z - vec2.z,2));
};


int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "raylib");
    
    



    for (i = 0; i < 255; i++){
        for (j = 0; j < 255; j++){
            for(k = 0; k < 3; k++){
            arr[i][j][k] = 1;
            }
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
    UpdateCamera(&cam, CAMERA_FREE);
    
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(cam);
    
            DrawGrid(10, 1.0f);
        EndMode3D();
        
        for (i = 0; i < 255; i++){
            for (j = 0; j < 255; j++){
                for (k = 0; k < 255; k++){
                    if (arr[i][k][j] == 1)
                    vx1.drawVoxelWires(vx1.getDots(i,j,k),(Color){i,k,j,255});
                }
            }
        }
        
        
    EndDrawing();
    //----------------------------------------------------------------------------------
}