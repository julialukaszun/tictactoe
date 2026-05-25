#pragma once //used to avoid duplicate definitions
#include "raylib.h"

class Button {
public:
    Button(Vector2 buttonPosition, Vector2 buttonSize, Color buttonColor, bool buttonDisabled); //constructor
    ~Button();
    void Draw();
    bool isPressed(Vector2 mousePos, bool mousePressed);
    Color color;
    bool disabled;

private:
    Vector2 position;
    Vector2 size;



};

