#include "birdClass.hpp"
#include <stdexcept>

// Construtores e destrutores

Bird::Bird(float pos_x_inicial, float pos_y_inicial, const std::string &bird_img_path) : vel_y(0), pos_x(pos_x_inicial), pos_y(pos_y_inicial),
BIRD_IMG_PATH(bird_img_path), bird(al_load_bitmap(bird_img_path.c_str())){
    if(bird == nullptr){
        throw std::runtime_error("Erro ao inicializar o pássaro: " + bird_img_path);
    }
}

Bird::Bird(const std::string& bird_img_path) : vel_y(0), BIRD_IMG_PATH(bird_img_path), bird(al_load_bitmap(bird_img_path.c_str())){
        if(bird == nullptr){
        throw std::runtime_error("Erro ao inicializar o pássaro: " + bird_img_path);
    }
}

Bird::~Bird(){
    if(bird) al_destroy_bitmap(bird);
}


// Funções

void Bird::draw(){
    al_draw_bitmap(bird, this-> pos_x, this-> pos_y, 0);

}

void Bird::draw(float pos_x, float pos_y){
    al_draw_bitmap(bird, pos_x, pos_y, 0);
}

void Bird::update(float pos_x, float pos_y){
    this-> pos_x = pos_x;
    this-> pos_y = pos_y;
}

void Bird::update(){
    pos_x += 1;
    pos_y += vel_y;
}

void Bird::jump(){
    vel_y = -10;
}

void Bird::gravity(){
    if (vel_y < 0) { 
        vel_y += 0.4; 
    } else { 
        vel_y += 0.7; 
    }
}

// Getters

float Bird::get_pos_x() const {
    return this-> pos_x;
}

float Bird::get_pos_y() const {
    return this-> pos_y;
}

ALLEGRO_BITMAP *Bird::get_bitmap() const {
    return this-> bird;
}

std::string Bird::get_path() const {
    return this-> BIRD_IMG_PATH;
}