#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Tic Tac Toe");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawCircle(50, 50, 50, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}