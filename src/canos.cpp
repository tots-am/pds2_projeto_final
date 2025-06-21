/**
 * @file canos.cpp
 * @brief Implementação da classe Canos.
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <stdexcept> 
#include "canos.hpp"
#include "constants.hpp" 

using namespace std; 
const std::string pipe1_sprite = "./assets/sprites/pipe-green.png";
const std::string pipe2_sprite = "./assets/sprites/pipe-green-down.png";

// Construtores e destrutores

Canos::Canos(int pos_x_inicial, int index) : 
    x(pos_x_inicial + (index * ESPACO_ENTRE_OS_CANOS)), 
    altura_cima(rand() % 200 + 50), 
    largura(100), 
    tamanho_buraco(250),
    canoCima(al_load_bitmap(pipe1_sprite.c_str())),
    canoBaixo(al_load_bitmap(pipe2_sprite.c_str()))
    
{

    if (!canoCima) {
        throw runtime_error("Erro ao carregar a imagem do cano de cima: " + pipe1_sprite);
    }
    if (!canoBaixo) {
        throw runtime_error("Erro ao carregar a imagem do cano de baixo: " + pipe2_sprite);
    }
    
    altura_baixo = SCREEN_HEIGHT - altura_cima - tamanho_buraco - ALTURA_BASE;
}

Canos::~Canos(){
    if(canoCima) al_destroy_bitmap(canoCima);
     if(canoCima) al_destroy_bitmap(canoBaixo);
}


//Funções

void Canos::desenhar(){ 
    if (!canoCima || !canoBaixo) {
        return;
    }
    al_draw_scaled_bitmap(canoCima, 0, 0, largura, al_get_bitmap_height(canoCima), x, 0, largura, altura_cima, 0);
    al_draw_scaled_bitmap(canoBaixo, 0, 0, largura, al_get_bitmap_height(canoBaixo), x, altura_cima + tamanho_buraco, largura, altura_baixo, 0); 
}

void Canos::atualizar(Canos* canos, int numCanos){ 
    for(int i = 0; i < numCanos; i++){ 
        canos[i].x -= VELOCIDADE_CANO; 
        if(canos[i].x < - canos[i].largura){ 
            int ultimoCano = (i == 0) ? numCanos - 1 : i - 1; 
            canos[i].x = canos[ultimoCano].x + ESPACO_ENTRE_OS_CANOS; 
            canos[i].altura_cima = rand() % 200 + 50; 
            canos[i].altura_baixo = SCREEN_HEIGHT - canos[i].altura_cima - canos[i].tamanho_buraco - ALTURA_BASE; 
        }
    }
}
void Canos::reset_position(Canos* canos, int numCanos) {
    for(int i = 0; i < numCanos; i++){
        canos[i].x = SCREEN_WIDTH + (i * ESPACO_ENTRE_OS_CANOS);
        canos[i].altura_cima = rand() % 200 + 50; 
        canos[i].altura_baixo = SCREEN_HEIGHT - canos[i].altura_cima - tamanho_buraco - ALTURA_BASE;
    }
}

// Getters

int Canos::get_x() const {
    return this->x;
}

int Canos::get_altura_cima() const {
    return this->altura_cima;
}

int Canos::get_altura_baixo() const {
    return this->altura_baixo;
}

int Canos::get_largura() const {
    return this->largura;
}
