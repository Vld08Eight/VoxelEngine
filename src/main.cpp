#include "main.h"
//------------------------------------------------------------------------------------
// Program main entry point-mingw32-make cd build
//------------------------------------------------------------------------------------
int i,j,k,s = 0;
World world = World(50);
Mater dirt = Mater(GREEN);
Voxel vox1 = Voxel((Vector3){0,0,0}, dirt);
Macroblock macrB = Macroblock(8,(Vector3){0,0,0});

Chunk chunk = Chunk(8,8,(Vector3){0,0,0});

static void UpdateDrawFrame(void);




int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 960;
    const int screenHeight = 540;
    world.getChunkByIndex((Vector3){0,0,0}).getMacroblockByIndex((Vector3){0,0,0}).setVoxelByIndex((Vector3){0,0,0},dirt);
    InitWindow(screenWidth, screenHeight, "raylib");
    
    

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
    UpdateCamera(&world.camera, CAMERA_FREE);
    
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(world.camera);
            
            DrawGrid(10, 1.0f);
        EndMode3D();
        

        //DrawCircle((float)GetScreenWidth()/2, (float)GetScreenHeight()/2, 2.5f, BLACK);
        DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}