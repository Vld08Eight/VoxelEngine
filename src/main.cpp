#include "main.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int i,j,k,s;
Voxel arr[50][3][50];

World vx1;
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
    
    



    for (i = 0; i < 50; i++){
        for (j = 0; j < 3; j++){
            for(k = 0; k < 50; k++){
            arr[i][j][k] = Voxel((Vector3){i,j,k});
            std::cout << arr[i][j][k].getCoordinates().x << " " << arr[i][j][k].getCoordinates().y << " " << arr[i][j][k].getCoordinates().z << " " << std::endl;
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

        for (i = 0; i < 50; i++){
            for (j = 0; j < 3; j++){
                for (k = 0; k < 50; k++){
                    if (!arr[i][j][k].isEmpty())
                    vx1.drawVoxelWires(arr[i][j][k],vx1.getDots(arr[i][j][k]));
                }
            }
        }
        DrawFPS(10, 10);
        
    EndDrawing();
    //----------------------------------------------------------------------------------
}