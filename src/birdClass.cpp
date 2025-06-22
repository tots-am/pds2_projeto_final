#include "birdClass.hpp"
#include <stdexcept>

// Constantes do passaro
const float gravidade = 800.0f;
const float jumpspeed = -300.0f;
const std::string bird_sprite = "./assets/sprites/yellowbird-midflap.png";

// Construtores e destrutores

using namespace std;

Bird::Bird(float pos_x_inicial, float pos_y_inicial) : 
        vel_y(0.0f),
        pos_x(pos_x_inicial), pos_y(pos_y_inicial),
        BIRD_IMG_PATH(bird_sprite), 
        bird(al_load_bitmap(bird_sprite.c_str()))
    {
        if (bird == nullptr) {
            throw std::runtime_error("Erro ao inicializar o pássaro: " + bird_sprite);
        }
        
        this->largura_obj = al_get_bitmap_width(bird);
        this->altura_obj = al_get_bitmap_height(bird);
        this->isJumping = false;
    }   

Bird::Bird() :
    vel_y(0.0f),
    pos_x(0.0f), pos_y(0.0f),
    BIRD_IMG_PATH(""),
    bird(nullptr),
    largura_obj(0.0f), altura_obj(0.0f),
    isJumping(false)
    {}    

Bird::~Bird(){
    al_destroy_bitmap(bird);
}

// Funções

void Bird::forced_draw(float pos_x, float pos_y) {
    al_draw_bitmap(bird, pos_x, pos_y, 0);
}

void Bird::reset_position(float pos_x, float pos_y) {
    this-> pos_x = pos_x;
    this-> pos_y = pos_y;
    this-> vel_y = 0;
}

void Bird::draw() {
    if (!bird) {
        return;
    }

    float draw_x = this->pos_x - (this->largura_obj / 2.0f);
    float draw_y =  this->pos_y - (this->altura_obj / 2.0f);

    al_draw_bitmap(bird, draw_x, draw_y, 0);

}

void Bird::update_position(double deltaTime){
    if (isJumping) {
        vel_y = jumpspeed;
        isJumping = false;
    } else {
        vel_y += gravidade * deltaTime;
    }

    pos_y += vel_y * deltaTime;

    // Limites da tela
    if (pos_y - altura_obj / 2 < 0) {
        pos_y = altura_obj / 2;
        vel_y = 0;
    }

    if (pos_y + altura_obj / 2 > 550) {
        pos_y = 580 - altura_obj / 2;
        vel_y = 0;
    }
}
bool Bird::borda_hit() const {
    if(this->pos_y >= 550){
        return true;
    } else {
        return false;
    }
}
void Bird::jump(){
    this->isJumping = true;
}

void Bird::gravity(){
    if (vel_y < 0) { 
        vel_y += 0.4; 
    } 
    else { 
         vel_y += 0.7; 
    }

    vel_y *= 0.98;
}

// Getters

float Bird::get_pos_x() const {
    return this-> pos_x;
}

float Bird::get_pos_y() const {
    return this-> pos_y;
}

float Bird::get_vel_y() const {
    return this->vel_y;
}

ALLEGRO_BITMAP *Bird::get_bitmap() const {
    return this-> bird;
}

std::string Bird::get_path() const {
    return this-> BIRD_IMG_PATH;
}