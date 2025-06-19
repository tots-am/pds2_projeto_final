/**
 * @file canos.cpp
 * @brief Implementação da classe canos.
 */


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include "../include/canos.hpp";
#include "../include/constante.hpp";

class Canos {
    
    private:
    int x = 0; 
    int altura_cima = 0; 
    int altura_baixo = 0; 
    int largura = 100; 
    int tamanho_buraco = 250; 

    public:

    void inicializarCanos(int posX, int index){ 
        x = posX + (index * ESPACO_ENTRE_OS_CANOS); 
        altura_cima = rand() % 200 + 50; 
        altura_baixo = SCREEN_HEIGHT - altura_cima - tamanho_buraco - ALTURA_BASE;
    }

    void desenhar(ALLEGRO_BITMAP* canoCima, ALLEGRO_BITMAP* canoBaixo){ 
        al_draw_scaled_bitmap(canoCima, 0, 0, largura, al_get_bitmap_height(canoCima), x, 0, largura, altura_cima, 0);
        al_draw_scaled_bitmap(canoBaixo, 0, 0, largura, al_get_bitmap_height(canoBaixo), x, altura_cima + tamanho_buraco, largura, altura_baixo, 0); 
    }

    void atualizar(Canos canos[]){ 
        for(int i = 0; i < NUM_CANOS; i++){ 
            canos[i].x -= VELOCIDADE_CANO; 
            if(canos[i].x < - canos[i].largura){ 
                int ultimoCano = (i == 0) ? NUM_CANOS - 1 : i - 1; 
                canos[i].x = canos[ultimoCano].x + ESPACO_ENTRE_OS_CANOS; 
                canos[i].altura_cima = rand() % 200 + 50; 
                canos[i].altura_baixo = SCREEN_HEIGHT - canos[i].altura_cima - tamanho_buraco - ALTURA_BASE; 
            }
        }
    }
};