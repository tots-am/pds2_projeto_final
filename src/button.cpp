#include "button.hpp"

Button::Button(int x1, int y1, int x2, int y2) :
    x1(x1), y1(y1), x2(x2), y2(y2)
{}

Button::~Button()
{}

bool Button::isMouseHovering(int x, int y)
{
    bool isHovering = false;
    if(x > x1 && x < x2){
        if (y > y1 && y < y2)
        {
            isHovering = true;
        }
    }
    return isHovering;
}
void Button::draw()
{
    al_draw_filled_rounded_rectangle(this->x1, this->y1, this->x2, this->y2, 10, 10, al_map_rgb(255, 255, 255));
}