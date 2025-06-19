/**
 * @file canos.hpp
 * @brief Classe para a construção e atualização dos obstáculos do jogo - Canos
 */


#ifndef CANOS_HPP
#define CANOS_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include "../include/constante.hpp";


class Canos {

    /**
     * @brief Atributos da Classe.
     * @var x A posição inicial do cano.
     * @var altura_cima Altura, ou seja, tamanho do cano de cima.
     * @var altura_baixo Altura, ou seja, tamanho do cano de baixo.
     * @var largura Largura de cada cano.
     * @var tamanho_buraco Espaço entre os canos - buraco, no qual o passáro deverá passar.
     */
    
    private:
    int x = 0; 
    int altura_cima = 0; 
    int altura_baixo = 0; 
    int largura = 100; 
    int tamanho_buraco = 250; 

    public:

    /**
     * @brief Inicializa os canos na tela.
     * @param posX Respresenta a posição do primeiro cano. index - é usado para calcular a posição do próximo cano
     * @param index Usado para calcular a posição do próximo cano
     * @return void
     * @details  
     *  A posição x de cada cano é baseada na posição do primeiro multiplicado pela index que ele representa no vetor de objetos Canos vezes o espaço definido de um cano para o outro.
        A altura é calculada randomicamente entre 50 e 250px.
        A altura do cano de baixo é calculada a partir do tamanho da tela menos a altura do cano de cima menos a altura do buraco (no qual o passáro passa) menos a altura do "chão".
     */

    void inicializarCanos(int posX, int index); 

    /**
     * @brief Desenha os canos na tela.
     * @param posX Ponteiros para as imagens dos canos.
     * @return void
     * @details 
     * Os dois métodos são responsáveis por renderizar os dois componentes do cano
     * no jogo: a parte superior e a parte inferior. As posições são calculadas
     * com base na altura da parte superior, na largura do cano e no tamanho do espacoço entre eles (o "buraco").
     */


    void desenhar(ALLEGRO_BITMAP*, ALLEGRO_BITMAP*); 

    /**
     * @brief
     * Simula o movimentos dos canos da direita para a esquerda. Reposiciona os canos na tela. Randomiza a dificuldade do cano
     * @param Vetor de objetos cano
     * @return void
     * @details
     * A função itera sobre cada cano no vetor
     * - Diminui a coordenada 'x' do cano para simular movimento
     * - Se a coordenada 'x' de um cano for menor que sua largura (indicando que ele saiu da tela), ele é reiniciado.
     * - Sua posição 'x' é definida com base no 'x' do último cano visível e no espaço entre os canos, garantindo que ele apareça após o último
     * - A altura da parte superior do cano é randomizada.
     * - A altura da parte inferior do cano é recalculada. 
     */

    void atualizar(Canos);

};

#endif