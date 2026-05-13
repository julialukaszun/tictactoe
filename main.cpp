#include "raylib.h"
#include <iostream>
#include "button.h"

int main()
{
    InitWindow(500, 500, "Tic Tac Toe");

    // top row
    Button t1{{90, 80},{100,100},{RED}};

    Button t2{{200, 80},{100,100},{RED}};

    Button t3{{310, 80},{100,100},{RED}};

    // middle row
    Button t4{{90, 190},{100,100},{RED}};

    Button t5{{200, 190},{100,100},{RED}};

    Button t6{{310, 190},{100,100},{RED}};

    // bottom row
    Button t7{{90, 300},{100,100},{RED}};

    Button t8{{200, 300},{100,100},{RED}};

    Button t9{{310, 300},{100,100},{RED}};

    Button tiles[9] = {t1,t2,t3,t4,t5,t6,t7,t8,t9};
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        for (int i = 0; i<9; i++) {
            if (tiles[i].isPressed(mousePosition, mousePressed)) {
                tiles[i].color = BLUE;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (Button tile : tiles) {
            tile.Draw();
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}