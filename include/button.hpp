#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <string>
class Button{
    public:
    int x1, y1, x2, y2, altura, largura;
    ALLEGRO_FONT *fonte;
    ALLEGRO_COLOR cor;

    Button(int altura, int largura, ALLEGRO_FONT *fonte, ALLEGRO_COLOR cor);
    ~Button();
    bool isMouseHovering(int x, int y);
    void draw(int x_offset, int y_offset);
    void draw(int x_offset, int y_offset, std::string message);
};

#endif