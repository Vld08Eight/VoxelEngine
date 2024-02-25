#include "main.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int i,j,k,s = 0;

World world = World(200);
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
                world.setVoxelByIndex(i,j,k);
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
    UpdateCamera(&world.camera, CAMERA_FREE);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        s++;
        if (s > 5)s = 0;
    }
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(world.camera);
            
            DrawGrid(10, 1.0f);
        EndMode3D();

        ///for (i = 0; i < 150; i++){
        //    for (j = 0; j < 1; j++){
        //        for (k = 0; k < 150; k++){
        //            VoxelRender::DrawFace(world.getVoxelByIndex(i,j,k).getFaceByNum(0),world.camera);
        //        }
        //    }
        //}
        VoxelRender::DrawFace(world.getVoxelByIndex(0,0,0).getFaceByNum(s),world.camera);
        VoxelRender::DrawFaceWires(world.getVoxelByIndex(0,0,0).getFaceByNum(s),world.camera);
        DrawFPS(10, 10);
        
    EndDrawing();
    //----------------------------------------------------------------------------------
}