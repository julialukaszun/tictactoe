#include "button.h"

Button::Button(Vector2 buttonPosition, Vector2 buttonSize, Color buttonColor, bool buttonPressed) {
    position = buttonPosition;
    size = buttonSize;
    color = buttonColor;
    pressed = buttonPressed;

}

Button::~Button() {

}

void Button::Draw() {

    DrawRectangleV(position, size, color);

}

bool Button::isPressed(Vector2 mousePos, bool mousePressed) {
    Rectangle rect = {position.x, position.y, size.x, size.y};

    if (CheckCollisionPointRec(mousePos, rect) && mousePressed) {
        return true;
    }
    return false;
}
