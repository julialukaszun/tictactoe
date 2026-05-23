#include "raylib.h"
#include <iostream>
#include "button.h"
#include "player.h"

bool checkWin(Button tiles[]) {
    if ((tiles[0].pressed && tiles[1].pressed && tiles[2].pressed)
    && (ColorIsEqual(tiles[0].color, tiles[1].color)
    && (ColorIsEqual(tiles[1].color, tiles[2].color)
    && (ColorIsEqual(tiles[0].color, tiles[2].color)))))
    {     // top row
        return true;
    }

    else if ((tiles[3].pressed && tiles[4].pressed && tiles[5].pressed)
    && (ColorIsEqual(tiles[3].color, tiles[4].color)
    && (ColorIsEqual(tiles[4].color, tiles[5].color)
    && (ColorIsEqual(tiles[3].color, tiles[5].color)))))
    {    // middle row
        return true;
    }

    else if ((tiles[6].pressed && tiles[7].pressed && tiles[8].pressed)
        && (ColorIsEqual(tiles[6].color, tiles[7].color)
        && (ColorIsEqual(tiles[7].color, tiles[8].color)
        && (ColorIsEqual(tiles[6].color, tiles[8].color)))))
    {
        // bottom row
        return true;
    }
    else if ((tiles[0].pressed && tiles[3].pressed && tiles[6].pressed)
        && (ColorIsEqual(tiles[0].color, tiles[3].color)
        && (ColorIsEqual(tiles[3].color, tiles[6].color)
        && (ColorIsEqual(tiles[0].color, tiles[6].color)))))
    { // left column
        return true;
    }

    else if ((tiles[1].pressed && tiles[4].pressed && tiles[7].pressed)
        && (ColorIsEqual(tiles[1].color, tiles[4].color)
        && (ColorIsEqual(tiles[4].color, tiles[7].color)
        && (ColorIsEqual(tiles[1].color, tiles[7].color)))))
    { // middle column
        return true;
    }

    else if ((tiles[2].pressed && tiles[5].pressed && tiles[8].pressed)
        && (ColorIsEqual(tiles[2].color, tiles[5].color)
        && (ColorIsEqual(tiles[5].color, tiles[8].color)
        && (ColorIsEqual(tiles[2].color, tiles[8].color)))))
    { // right column
            return true;
        }

    else if ((tiles[0].pressed && tiles[4].pressed && tiles[8].pressed)
        && (ColorIsEqual(tiles[0].color, tiles[4].color)
        && (ColorIsEqual(tiles[4].color, tiles[8].color)
        && (ColorIsEqual(tiles[0].color, tiles[8].color)))))
    { // cross from top to bottom
            return true;
        }

    else if ((tiles[6].pressed && tiles[4].pressed && tiles[2].pressed)
        && (ColorIsEqual(tiles[6].color, tiles[4].color)
        && (ColorIsEqual(tiles[4].color, tiles[2].color)
        && (ColorIsEqual(tiles[6].color, tiles[2].color)))))
    { // cross from bottom to top
            return true;
        }
    else {
        return false;
    }
}

int main()
{
    typedef enum GameScreen { TITLE = 0,GAMEPLAY} GameScreen;
    GameScreen currentScreen = TITLE;

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
    int turns = 0;
    Color currentColor = {WHITE};

    Player p1{{GREEN},false,true};
    Player p2{{PINK},false,false};

    while (!WindowShouldClose() && !done)
    {
        switch (currentScreen) {
            case TITLE:
                if (IsKeyPressed(KEY_ENTER)) {
                    currentScreen = GAMEPLAY;
                }
            case GAMEPLAY:
                Vector2 mousePosition = GetMousePosition();
                bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

                for (int i = 0; i < 9; i++) {
                    if (tiles[i].isPressed(mousePosition, mousePressed)) {
                        turns++;
                        if (p1.turn) {
                            currentColor = p1.color;
                            tiles[i].color = p1.color;
                            p1.turn = false;
                            p2.turn = true;
                        }
                        else {
                            currentColor = p2.color;
                            tiles[i].color = p2.color;
                            p1.turn = true;
                            p2.turn = false;
                        }
                        tiles[i].pressed = true;
                    }
                }

                if (checkWin(tiles)) {
                    if (ColorIsEqual(p1.color, currentColor)) {
                        std::cout << "PLAYER 1 WINS!" << std::endl;
                    }
                    else if (ColorIsEqual(p2.color, currentColor)) {
                        std::cout << "PLAYER 2 WINS!" << std::endl;
                    }
                    done = true;
                }

                else if (turns >= 9) {
                    std::cout << "TIE!" << std::endl;
                    done = true;
                } break;
        }


            BeginDrawing();
            ClearBackground(RAYWHITE);

            switch(currentScreen) {
                case TITLE: {
                    DrawText("TIC TAC TOE", 90, 200, 50, DARKGREEN);
                    DrawText("PRESS 'enter' TO PLAY", 120, 300, 20, DARKGREEN);
                } break;

                case GAMEPLAY:
                {
                    for (Button tile: tiles) {
                        tile.Draw();
                    }
                } break;
            }
            EndDrawing();
    }

    CloseWindow();

    return 0;
}