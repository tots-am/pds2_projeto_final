/**
 * @file canos.cpp
 * @brief Implementação da classe Canos.
 */

#include <iostream>
#include <stdexcept> 
#include "canos.hpp"
#include "constants.hpp"

;using namespace std;

float Canos::VELOCIDADE_CANO = 100;


// Construtores e destrutores

Canos::Canos(int pos_x_inicial, int index, string cano_cima_path, string cano_baixo_path) : 
    x(pos_x_inicial + (index * ESPACO_ENTRE_OS_CANOS)), 
    altura_cima(rand() % 200 + 50),
    tamanho_buraco(TAMANHO_BURACO_CANOS),
    canoCima(al_load_bitmap(cano_cima_path.c_str())),
    canoBaixo(al_load_bitmap(cano_baixo_path.c_str()))
    
{

    if (!canoCima) {
        throw runtime_error("Erro ao carregar a imagem do cano de cima: " + cano_cima_path);
    }
    if (!canoBaixo) {
        throw runtime_error("Erro ao carregar a imagem do cano de baixo: " + cano_baixo_path);
    }
    
    altura_baixo = SCREEN_HEIGHT - altura_cima - tamanho_buraco - ALTURA_BASE;
    this->largura = al_get_bitmap_width(canoCima);
}

Canos::~Canos(){
    if(canoCima) al_destroy_bitmap(canoCima);
    if(canoBaixo) al_destroy_bitmap(canoBaixo);
}


//Funções

void Canos::desenhar(){ 
    if (!canoCima || !canoBaixo) {
        return;
    }
    al_draw_scaled_bitmap(canoCima, 0, 0, largura, al_get_bitmap_height(canoCima), x, 0, largura, altura_cima, 0);
    al_draw_scaled_bitmap(canoBaixo, 0, 0, largura, al_get_bitmap_height(canoBaixo), x, altura_cima + tamanho_buraco, largura, altura_baixo, 0); 
}

void Canos::atualizar(Canos* canos, int numCanos, double deltaTime, float tempo){ 
    VELOCIDADE_CANO = 100 + tempo / FATOR_DIFICULDADE;
    if(VELOCIDADE_CANO > 350) VELOCIDADE_CANO = 350;

    for(int i = 0; i < numCanos; i++){ 
        canos[i].x -= VELOCIDADE_CANO * deltaTime; 
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

int Canos::get_y_baixo() const {
    return this->altura_cima + this->tamanho_buraco;
}