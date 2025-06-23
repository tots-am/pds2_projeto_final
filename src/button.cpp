#include "button.hpp"

Button::Button(int altura, int largura, ALLEGRO_FONT *fonte, ALLEGRO_COLOR cor) :
    x1(0), y1(0), x2(x1 + largura), y2(y1 + altura), altura(altura), largura(largura), fonte(fonte), cor(cor), active(false)
{}

Button::~Button()
{}

ALLEGRO_COLOR Button::get_cor()
{
    return cor;
}

void Button::set_cor(ALLEGRO_COLOR cor)
{
    this->cor = cor;
}

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
bool Button::isActive()
{
    return active;
}
void Button::switchActive()
{
    if(active) active = false;
    else active = true;
}
void Button::draw(int x_offset, int y_offset, int filled)
{
    if(filled < 0 || filled > 1) filled = 0;
    this->x1 = x_offset;
    this->y1 = y_offset;
    this->x2 = x_offset + largura;
    this->y2 = y_offset + altura;
    if(filled == 0) al_draw_rounded_rectangle(this->x1, this->y1, this->x2, this->y2, 10, 10, cor, 5);
    if(filled == 1) al_draw_filled_rounded_rectangle(this->x1, this->y1, this->x2, this->y2, 10, 10, cor);
}

void Button::draw(int x_offset, int y_offset, int filled, std::string message, ALLEGRO_COLOR cor_msg) {
    if(filled < 0 || filled > 1) filled = 0;
    this->x1 = x_offset;
    this->y1 = y_offset;
    this->x2 = x_offset + largura;
    this->y2 = y_offset + altura;
    if(filled == 1)al_draw_filled_rounded_rectangle(this->x1, this->y1, this->x2, this->y2, 10, 10, cor);
    if(filled == 0)al_draw_rounded_rectangle(this->x1, this->y1, this->x2, this->y2, 10, 10, cor, 5);
    al_draw_text(fonte, cor_msg, x1 + largura/2, y1, ALLEGRO_ALIGN_CENTER, message.c_str());
}
