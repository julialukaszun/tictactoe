#include "raylib.h"
#include "button.h"

int main()
{
    InitWindow(800, 450, "Tic Tac Toe");

    Button tile{{150, 300},{40,40},{RED}};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        tile.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}