#include<raylib.h>
#include <iostream>

using namespace std;

Color green = {173,204,96,255 };
Color darkGreen = {43, 51,24, 255 };
Color red = {255, 0, 0, 255};

//Grid of 750 by 750 pixels (25 * 30)
int cellSize = 30;
int cellCount = 25;

class Food {

public:
    Vector2 position = {5, 6};//Vector 2 Struct attributes

    void Draw()
    {
        DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
    }

};

int main() {
    int screen_width = 750;
    int screen_height = 750;

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Shnake");
    SetTargetFPS(60);

    //Create Objects
    Food food = Food();



    //GAME LOOP
    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        //Drawing
        ClearBackground(green);
        food.Draw();


        EndDrawing();
    }

    //Event Handling


    //Updating Positions







    CloseWindow();
    return 0;

}