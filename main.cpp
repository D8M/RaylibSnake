#include<raylib.h>
#include <iostream>

using namespace std;
Color green = {173,204,96,255 };
Color darkGreen = {43, 51, 255 };

//Grid of 750 by 750 pixels ( 25 * 30)
int cellSize = 30;
int cellCount = 25;

int main() {
    int screen_width = 750;
    int screen_height = 750;

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Shnake");
    SetTargetFPS(60);




    //GAME LOOP
    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        //Drawing
        ClearBackground(green);



        EndDrawing();
    }

    //Event Handling


    //Updating Positions







    CloseWindow();
    return 0;

}