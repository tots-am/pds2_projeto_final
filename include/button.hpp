#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <string>
class Button{
    private:
    int x1, y1, x2, y2, altura, largura;
    ALLEGRO_FONT *fonte;
    ALLEGRO_COLOR cor;
    bool active;

    public:
    Button(int altura, int largura, ALLEGRO_FONT *fonte, ALLEGRO_COLOR cor);
    ~Button();
    ALLEGRO_COLOR get_cor();
    bool isMouseHovering(int x, int y);
    bool isActive();
    void switchActive();
    void draw(int x_offset, int y_offset, int filled);
    void draw(int x_offset, int y_offset, int filled, std::string message, ALLEGRO_COLOR cor_msg);
};

#endif