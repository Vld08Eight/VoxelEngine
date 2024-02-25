#include "main.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int i,j,k,s;
Voxel arr[150][1][150];

World vx1;
static void UpdateDrawFrame(void);


int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "raylib");
    
    



    for (i = 0; i < 150; i++){
        for (j = 0; j < 1; j++){
            for(k = 0; k < 150; k++){
            arr[i][j][k] = Voxel((Vector3){i,j,k});
            //std::cout << arr[i][j][k].getCoordinates().x << " " << arr[i][j][k].getCoordinates().y << " " << arr[i][j][k].getCoordinates().z << " " << std::endl;
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
    UpdateCamera(&vx1.camera, CAMERA_FREE);
    
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(vx1.camera);
            
            DrawGrid(10, 1.0f);
        EndMode3D();

        for (i = 0; i < 150; i++){
            for (j = 0; j < 1; j++){
                for (k = 0; k < 150; k++){
                    VoxelRender::DrawFace(arr[i][j][k].getFaceByNum(2),vx1.camera);
                }
            }
        }
        

        DrawFPS(10, 10);
        
    EndDrawing();
    //----------------------------------------------------------------------------------
}