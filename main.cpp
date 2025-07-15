#include <raylib.h>
#include <iostream>
#include <deque>
#include <raymath.h>

using namespace std;

Color green = {173,204,96,255 };
Color darkGreen = {43, 51,24, 255 };
Color red = {255, 0, 0, 255};

//Grid of 750 by 750 pixels (25 * 30)
int cellSize = 30;
int cellCount = 25;

double lastUpdateTime = 0;

bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++) // Check every element in the deque length
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;

}

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;



}

class Snake
{
public:
    deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
    Vector2 direction = { 1 ,0};
    bool addSegment = false;

    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{x * cellSize, y * cellSize, (float)cellSize, (float)cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update()
    {
        body.push_front(Vector2Add(body[0], direction));
        if (addSegment == true)
        {
            addSegment = false;

        }else
        {
            body.pop_back();

        }

    }


};

class Food { // Food Class

public:
    Vector2 position ;//Vector 2 Struct attributes -> Removed due to GetRandomPos method
    Texture2D texture;

    Food(deque<Vector2> snakeBody)
    { //Constructor
      Image image = LoadImage("textures/food.png");
        texture = LoadTextureFromImage(image);
        
        UnloadImage(image);
        position = GenerateRandomPos(snakeBody);
    }
    //Destructor
    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw() // Method
    {
        //DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomCell()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }

    Vector2 GenerateRandomPos(deque<Vector2> snakeBody) //Random position for food and snake position check
    {

        Vector2 position = GenerateRandomCell();
        //return Vector2{x, y};
        while (ElementInDeque(position, snakeBody))
        {
            position = GenerateRandomCell();
        }
        return position;
    }

};

class Game
{
public:
    Snake snake =Snake();
    Food food = Food(snake.body);

    void Draw()
    {
        food.Draw();
        snake.Draw();
    }

    void Update() // Update methods of the game classes here
    {
        snake.Update();
        CheckCollisionWithFood();
    }

    void CheckCollisionWithFood() // Method
    {
        if (Vector2Equals(snake.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snake.body);
            snake.addSegment = true;
        }
    }

};

int main() {
    int screen_width = 750;
    int screen_height = 750;

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Shnake");
    SetTargetFPS(60);

    //Create Objects
    //Food food = Food();
    //Snake snake = Snake();

    Game game = Game();


    //GAME LOOP
    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        if (eventTriggered(0.2))
        {
            game.Update();
        }

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
            game.snake.direction = { 0 , -1};
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
            game.snake.direction = { 0 , 1};
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 ) {
            game.snake.direction = { -1 , 0};
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
            game.snake.direction = { 1 , 0};
        }




        //Drawing
        ClearBackground(green);
        game.Draw();



        EndDrawing();
    }

    //Event Handling


    //Updating Positions







    CloseWindow();
    return 0;

}