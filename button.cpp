#include "button.h"

Button::Button(Vector2 buttonPosition, Vector2 buttonSize, Color buttonColor) {
    position = buttonPosition;
    size = buttonSize;
    color = buttonColor;

}

Button::~Button() {

}

void Button::Draw() {

    DrawRectangleV(position, size, color);

}
