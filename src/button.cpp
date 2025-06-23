#include "button.hpp"

Button::Button(int altura, int largura) :
    x1(0), y1(0), x2(x1 + largura), y2(y1 + altura), altura(altura), largura(largura)
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
void Button::draw(int x_offset, int y_offset)
{
    this->x1 = x_offset;
    this->y1 = y_offset;
    this->x2 = x_offset + largura;
    this->y2 = y_offset + altura;
    al_draw_rounded_rectangle(this->x1, this->y1, this->x2, this->y2, 10, 10, al_map_rgb(255, 255, 255), 3);
}