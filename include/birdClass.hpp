#ifndef BIRD_CLASS_HPP
#define BIRD_CLASS_HPP

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

class Bird{

    enum Estados {PULO, MORTO};

    ALLEGRO_BITMAP *bird;
    float pos_x, pos_y;
    float largura_obj, altura_obj; 
    float vel_y;
    std::string BIRD_IMG_PATH;


    public:

    Bird(float pos_x_inicial, float pos_y_inicial, const std::string& bird_img_path);
    Bird(const std::string& bird_img_path);

    ~Bird();

    float get_pos_y() const;
    float get_pos_x() const;
    float get_vel_y() const;
    bool borda_hit() const;
    std::string get_path() const;
    ALLEGRO_BITMAP *get_bitmap() const;

    void jump();
    void gravity();

    void draw();
    void update();

    void forced_draw(float pox_x, float pos_y);
    void forced_update(float pox_x, float pos_y);

};



#endif