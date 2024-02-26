#include "main.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int i,j,k,s = 0;

World world = World(50);
static void UpdateDrawFrame(void);




int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 960;
    const int screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "raylib");
    
    



    for (i = 0; i < 50; i++){
        for (j = 0; j < 1; j++){
            for(k = 0; k < 50; k++){
                if ((i+k)%2==0)
                world.setVoxelByIndex(i,j,k, (Color){200,200,200,255});
                else if ((i+k)%2!=0)
                world.setVoxelByIndex(i,j,k, (Color){100,100,100,255});
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
        //s++;
        //if (s > 5)s=0;
        //ray = GetMouseRay((Vector2){(float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f},world.camera);
        
    }
    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(world.camera);
            
            DrawGrid(10, 1.0f);
        EndMode3D();
        std::vector<Voxel> rendArr = VoxelRender::getRenderArray(world.camera, world);
        VoxelRender::DrawVoxelsVec(rendArr,world.camera,world);

        
        VoxelRender::DrawVoxelWires(VoxelRender::isSelected(rendArr,world.camera),world.camera);
        
        //VoxelRender::DrawFace(world.getVoxelByIndex(0,0,0).getFaceByNum(s),world.camera,world.getVoxelByIndex(0,0,0).getColor());
        
        
        DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}