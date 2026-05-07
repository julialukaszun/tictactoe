#include "raylib.h"
#include <iostream>
#include "button.h"

int main()
{
    InitWindow(800, 450, "Tic Tac Toe");

    Button tile{{150, 300},{40,40},{RED}};

    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (tile.isPressed(mousePosition, mousePressed)) {
            std::cout << "Tile Button Pressed" << std::endl;

        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        tile.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}