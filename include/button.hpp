#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <allegro5/allegro_primitives.h>

class Button{
    public:
    int x1, y1, x2, y2;

    Button(int x1, int y1, int x2, int y2);
    ~Button();
    bool isMouseHovering(int x, int y);
    void draw();
};

#endif