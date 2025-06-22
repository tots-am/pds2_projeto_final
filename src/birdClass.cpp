#include "birdClass.hpp"
#include <stdexcept>

// Constantes do passaro
const float gravidade = 800.0f;
const float jumpspeed = -300.0f;

// Construtores e destrutores

using namespace std;

Bird::Bird(float pos_x_inicial, float pos_y_inicial, Imagem sprite) : 
        vel_y(0.0f),
        pos_x(pos_x_inicial), pos_y(pos_y_inicial),
        bird(sprite)
    {
        this->largura_obj = bird.largura;
        this->altura_obj = bird.altura;
        this->isJumping = false;
    }   

Bird::Bird() :
    vel_y(0.0f),
    pos_x(0.0f), pos_y(0.0f),
    bird(nullptr),
    largura_obj(0.0f), altura_obj(0.0f),
    isJumping(false)
    {}    

Bird::~Bird()
{}

// Funções

void Bird::forced_draw(float pos_x, float pos_y) {
    bird.exibir(pos_x, pos_y);
}

void Bird::reset_position(float pos_x, float pos_y) {
    this-> pos_x = pos_x;
    this-> pos_y = pos_y;
    this-> vel_y = 0;
}

void Bird::draw() {
    if (!bird.isLoaded()) {
        return;
    }

    float draw_x = this->pos_x - (this->largura_obj / 2.0f);
    float draw_y =  this->pos_y - (this->altura_obj / 2.0f);

    bird.exibir(draw_x, draw_y);
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
        pos_y = 600 - altura_obj / 2;
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
    return this-> bird.imagem;
}

std::string Bird::get_path() const {
    return this->bird.path;
}
