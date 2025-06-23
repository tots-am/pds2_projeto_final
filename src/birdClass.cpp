#include "birdClass.hpp"
#include "constants.hpp"
#include <stdexcept>

// Construtores e destrutores

using namespace std;

Bird::Bird(float pos_x_inicial, float pos_y_inicial) : 
        vel_y(0.0f),
        pos_x(pos_x_inicial), pos_y(pos_y_inicial),
        sprite(BIRD_SPRITESHEET_PATH), 
        bird(al_load_bitmap(BIRD_SPRITESHEET_PATH.c_str())),
        cor(Yellow)
    {
        if (bird == nullptr) {
            throw std::runtime_error("Erro ao inicializar o pássaro: " + BIRD_SPRITESHEET_PATH);
        }
        
        this->largura_obj = 34;
        this->altura_obj = 24;
        this->isJumping = false;
    }   

Bird::Bird() :
    vel_y(0.0f),
    pos_x(0.0f), pos_y(0.0f),
    sprite(""),
    bird(nullptr),
    largura_obj(0.0f), altura_obj(0.0f),
    isJumping(false),
    cor(Yellow)
    {}    

Bird::~Bird(){
    al_destroy_bitmap(bird);
}

// Funções

void Bird::forced_draw(float pos_x, float pos_y) {
    switch (cor){
        case Yellow:
            al_draw_bitmap_region(bird, 34, 0, 34, 24, pos_x, pos_y, 0);
            break;
        case Red:
            al_draw_bitmap_region(bird, 34, 24, 34, 24, pos_x, pos_y, 0);
            break;
        case Blue:
            al_draw_bitmap_region(bird, 34, 48, 34, 24, pos_x, pos_y, 0);
            break;
    }
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

    switch (cor){
        case Yellow:
            if(this->vel_y < -150.0f) al_draw_bitmap_region(bird, 0, 0, 34, 24, draw_x, draw_y, 0);
            else if(this->vel_y < 0) al_draw_bitmap_region(bird, 34, 0, 34, 24, draw_x, draw_y, 0);
            else al_draw_bitmap_region(bird, 68, 0, 34, 24, draw_x, draw_y, 0);
            break;
        case Red:
            if(this->vel_y < -150.0f) al_draw_bitmap_region(bird, 0, 24, 34, 24, draw_x, draw_y, 0);
            else if(this->vel_y < 0) al_draw_bitmap_region(bird, 34, 24, 34, 24, draw_x, draw_y, 0);
            else al_draw_bitmap_region(bird, 68, 24, 34, 24, draw_x, draw_y, 0);
            break;
        case Blue:
            if(this->vel_y < -150.0f) al_draw_bitmap_region(bird, 0, 48, 34, 24, draw_x, draw_y, 0);
            else if(this->vel_y < 0) al_draw_bitmap_region(bird, 34, 48, 34, 24, draw_x, draw_y, 0);
            else al_draw_bitmap_region(bird, 68, 48, 34, 24, draw_x, draw_y, 0);
            break;
    }    
}

void Bird::update_position(double deltaTime){
    if (isJumping) {
        vel_y = JUMPSPEED;
        isJumping = false;
    } else {
        vel_y += GRAVIDADE * deltaTime;
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
bool Bird::borda_hit(Canos* lista_objetos) const {

    if(this->pos_y >= 550){
        return true;
    } 

    for(int i = 0; i < NUM_CANOS; i++){

        float bird_x = this->pos_x - (this->largura_obj / 2.0);
        float bird_y = this->pos_y - (this->altura_obj / 2.0);
        float bird_largura = this->largura_obj;
        float bird_altura = this->altura_obj;

        float cano_pos_x = lista_objetos[i].get_x();
        float cano_largura = lista_objetos[i].get_largura();

        float cano_cima_y = 0; 
        float cano_cima_altura = lista_objetos[i].get_altura_cima();

        float cano_baixo_y = lista_objetos[i].get_y_baixo();
        float cano_baixo_altura = lista_objetos[i].get_altura_baixo();

        bool colide_x = (bird_x < cano_pos_x + cano_largura) && (bird_x + bird_largura > cano_pos_x);
        bool colide_y_cano_baixo = (bird_y < cano_baixo_y + cano_baixo_altura) && (bird_y + bird_altura > cano_baixo_y);
        bool colide_y_cano_cima = (bird_y < cano_cima_y + cano_cima_altura) && (bird_y + bird_altura > cano_cima_y);

        if(colide_x && colide_y_cano_cima){
            return true;
        }
        if(colide_x && colide_y_cano_baixo){
            return true;
        }

    }
    return false;
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
    return this-> sprite;
}

BirdColor Bird::getCor()
{
    return this->cor;
}

void Bird::setCor(BirdColor cor){
    this->cor = cor;
}