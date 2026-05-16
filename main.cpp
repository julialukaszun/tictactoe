#include "raylib.h"
#include <iostream>
#include "button.h"

bool checkWin(Button tiles[]) {
    if (tiles[0].pressed && tiles[1].pressed && tiles[2].pressed) {     // top row
        return true;
    }

    else if (tiles[3].pressed && tiles[4].pressed && tiles[5].pressed) {    // middle row
        return true;
    }

    else if (tiles[6].pressed && tiles[7].pressed && tiles[8].pressed) {    // bottom row
        return true;
    }
    else if (tiles[0].pressed && tiles[3].pressed && tiles[6].pressed) {    // left column
        return true;
    }

    else if (tiles[1].pressed && tiles[4].pressed && tiles[7].pressed) {    // middle column
        return true;
    }

    else if (tiles[2].pressed && tiles[5].pressed && tiles[8].pressed) {    // right column
        return true;
    }

    else if (tiles[0].pressed && tiles[4].pressed && tiles[8].pressed) {    // cross from top to bottom
        return true;
    }

    else if (tiles[6].pressed && tiles[4].pressed && tiles[2].pressed) {     // cross from bottom to top
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    InitWindow(500, 500, "Tic Tac Toe");

    // top row
    Button t1{{90, 80},{100,100},{RED},false};

    Button t2{{200, 80},{100,100},{RED},false};

    Button t3{{310, 80},{100,100},{RED},false};

    // middle row
    Button t4{{90, 190},{100,100},{RED},false};

    Button t5{{200, 190},{100,100},{RED},false};

    Button t6{{310, 190},{100,100},{RED},false};

    // bottom row
    Button t7{{90, 300},{100,100},{RED},false};

    Button t8{{200, 300},{100,100},{RED},false};

    Button t9{{310, 300},{100,100},{RED},false};

    Button tiles[9] = {t1,t2,t3,t4,t5,t6,t7,t8,t9};

    bool done = false;

    while (!WindowShouldClose() && !done)
    {

            Vector2 mousePosition = GetMousePosition();
            bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

            for (int i = 0; i < 9; i++) {
                if (tiles[i].isPressed(mousePosition, mousePressed)) {
                    tiles[i].color = BLUE;
                    tiles[i].pressed = true;
                }
            }

            if (checkWin(tiles)) {
                std::cout << "winner!" << std::endl;
                done = true;
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);
            for (Button tile: tiles) {
                tile.Draw();
            }
            EndDrawing();
    }

    CloseWindow();

    return 0;
}