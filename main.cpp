#include "raylib.h"
#include <iostream>
#include <array>
#include "button.h"
#include "player.h"

typedef enum GameScreen { TITLE = 0,GAMEPLAY, WIN, TIE} GameScreen;


std::array<Button,9> initializeTileSet() {

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

    std::array<Button, 9> tiles = {t1,t2,t3,t4,t5,t6,t7,t8,t9};

    return tiles;

}

bool checkWin(std::array<Button,9> tiles) {
    if ((tiles[0].disabled && tiles[1].disabled && tiles[2].disabled)
    && (ColorIsEqual(tiles[0].color, tiles[1].color)
    && (ColorIsEqual(tiles[1].color, tiles[2].color)
    && (ColorIsEqual(tiles[0].color, tiles[2].color)))))
    {     // top row
        return true;
    }

    else if ((tiles[3].disabled && tiles[4].disabled && tiles[5].disabled)
    && (ColorIsEqual(tiles[3].color, tiles[4].color)
    && (ColorIsEqual(tiles[4].color, tiles[5].color)
    && (ColorIsEqual(tiles[3].color, tiles[5].color)))))
    {    // middle row
        return true;
    }

    else if ((tiles[6].disabled && tiles[7].disabled && tiles[8].disabled)
        && (ColorIsEqual(tiles[6].color, tiles[7].color)
        && (ColorIsEqual(tiles[7].color, tiles[8].color)
        && (ColorIsEqual(tiles[6].color, tiles[8].color)))))
    {
        // bottom row
        return true;
    }
    else if ((tiles[0].disabled && tiles[3].disabled && tiles[6].disabled)
        && (ColorIsEqual(tiles[0].color, tiles[3].color)
        && (ColorIsEqual(tiles[3].color, tiles[6].color)
        && (ColorIsEqual(tiles[0].color, tiles[6].color)))))
    { // left column
        return true;
    }

    else if ((tiles[1].disabled && tiles[4].disabled && tiles[7].disabled)
        && (ColorIsEqual(tiles[1].color, tiles[4].color)
        && (ColorIsEqual(tiles[4].color, tiles[7].color)
        && (ColorIsEqual(tiles[1].color, tiles[7].color)))))
    { // middle column
        return true;
    }

    else if ((tiles[2].disabled && tiles[5].disabled && tiles[8].disabled)
        && (ColorIsEqual(tiles[2].color, tiles[5].color)
        && (ColorIsEqual(tiles[5].color, tiles[8].color)
        && (ColorIsEqual(tiles[2].color, tiles[8].color)))))
    { // right column
            return true;
        }

    else if ((tiles[0].disabled && tiles[4].disabled && tiles[8].disabled)
        && (ColorIsEqual(tiles[0].color, tiles[4].color)
        && (ColorIsEqual(tiles[4].color, tiles[8].color)
        && (ColorIsEqual(tiles[0].color, tiles[8].color)))))
    { // cross from top to bottom
            return true;
        }

    else if ((tiles[6].disabled && tiles[4].disabled && tiles[2].disabled)
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
    GameScreen currentScreen = TITLE;

    InitWindow(500, 500, "Tic Tac Toe");

    std::array<Button, 9> tiles = initializeTileSet();

    int turns = 0;
    Color currentColor = {WHITE};

    Player p1{{GREEN},false,true};
    Player p2{{PINK},false,false};

    while (!WindowShouldClose())
    {
        switch (currentScreen) {
            case TITLE: {
                if (IsKeyPressed(KEY_ENTER)) {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY: {
                Vector2 mousePosition = GetMousePosition();
                bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

                for (int i = 0; i < 9; i++) {
                    if (tiles[i].isPressed(mousePosition, mousePressed) && !(tiles[i].disabled)) {
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
                        tiles[i].disabled = true;
                    }
                }

                if (checkWin(tiles)) {
                    if (ColorIsEqual(p1.color, currentColor)) {
                        p1.win = true;
                    }
                    else if (ColorIsEqual(p2.color, currentColor)) {
                        p2.win = true;
                    }
                    std::cout << "WIN!" << std::endl;
                    currentScreen = WIN;
                }

                else if (turns >= 9) {
                    std::cout << "TIE!" << std::endl;
                    currentScreen = TIE;
                }
            } break;

            case WIN: {
                if (IsKeyPressed(KEY_ENTER)) {
                    turns = 0;
                    p1.win = false;
                    p2.win = false;
                    tiles = initializeTileSet();
                    currentScreen = TITLE;
                }
            } break;

            case TIE: {
                if (IsKeyPressed(KEY_ENTER)) {
                    turns = 0;
                    tiles = initializeTileSet();
                    currentScreen = TITLE;
                }
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

                case WIN: {
                    if (p1.win) {
                        DrawText("PLAYER 1 WINS!", 50, 220, 50, GREEN);
                    }
                    else {
                        DrawText("PLAYER 2 WINS!", 50, 220, 50, PINK);
                    }

                } break;

                case TIE: {
                    DrawText("ITS A TIE!", 100, 220, 50, DARKGREEN);
                } break;

            }
            EndDrawing();
    }

    CloseWindow();

    return 0;
}