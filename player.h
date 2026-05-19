#pragma once //used to avoid duplicate definitions
#include "raylib.h"

class Player {

public:
    Player(Color playerColor, bool playerWin, bool playerTurn);
    Color color;
    bool win;
    bool turn;

};

