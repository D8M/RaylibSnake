#include <raylib.h>
#include <iostream>
#include <deque>

using namespace std;

Color green = {173,204,96,255 };
Color darkGreen = {43, 51,24, 255 };
Color red = {255, 0, 0, 255};

//Grid of 750 by 750 pixels (25 * 30)
int cellSize = 30;
int cellCount = 25;

class Snake
{
public:
    deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };

    void Draw()
    {
        for (int i = 0; i < body.size(); i++)
        {
            int x = body[i].x;
            int y = body[i].y;
            DrawRectangle( x*cellSize, y*cellSize, cellSize, cellSize, darkGreen);
        }
    }
};

class Food {

public:
    Vector2 position ;//Vector 2 Struct attributes -> Removed due to GetRandomPos method
    Texture2D texture;

    Food()
    { //Constructor
      Image image = LoadImage("textures/food.png");
        texture = LoadTextureFromImage(image);
        
        UnloadImage(image);
        position = GenerateRandomPos();
    }
    //Destructor
    ~Food()
    {
        UnloadTexture(texture);
    }



    void Draw()
    {
        //DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos() //Random position for food
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }

};

int main() {
    int screen_width = 750;
    int screen_height = 750;

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Shnake");
    SetTargetFPS(60);

    //Create Objects
    Food food = Food();
    Snake snake = Snake();



    //GAME LOOP
    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        //Drawing
        ClearBackground(green);
        food.Draw();
        snake.Draw();


        EndDrawing();
    }

    //Event Handling


    //Updating Positions







    CloseWindow();
    return 0;

}