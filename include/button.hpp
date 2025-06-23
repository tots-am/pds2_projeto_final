#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <allegro5/allegro_primitives.h>

class Button{
    public:
    int x1, y1, x2, y2, altura, largura;

    Button(int altura, int largura);
    ~Button();
    bool isMouseHovering(int x, int y);
    void draw(int x_offset, int y_offset);
};

#endif