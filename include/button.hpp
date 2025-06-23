/// @file button.hpp

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <string>

/**
 * @class Button
 * @brief Representa os botões e caixas de texto que o usuário pode usar
 * 
 * A classe é resposável por criar, destruir, desenhar, e detectar cliques do mouse nos botões
 */

class Button{
    private:
    int x1, y1, x2, y2, altura, largura;
    ALLEGRO_FONT *fonte;
    ALLEGRO_COLOR cor;
    bool active;

    public:

    /**
     * @brief Construtor principal que cria o botão com uma altura, largura, fonte do texto, e cor pre-definidas
     * 
     * @param altura Altura do Botão em pixels
     * @param largura Largura do Botão em pixels
     * @param fonte Fonte que será usada para escrever a mensagem do botão, caso houver.
     * @param cor Cor que será usada para desenhar o botão
     * 
     * @note Inicia active como false por default, e calcula x1, x2, y1, y2 por conta propria
    */
    Button(int altura, int largura, ALLEGRO_FONT *fonte, ALLEGRO_COLOR cor);
    /**
     * @brief Destrutor Padrão
     */
    ~Button();
    /**
     * @return Retorna a cor que o botão está, no padrão RBG
     */
    ALLEGRO_COLOR get_cor();
    /**
     * @brief Usado para redefinir a cor de um botão em tempo de execução
     * @param cor A nova cor que o botão terá
     */
    void set_cor(ALLEGRO_COLOR cor);
    /**
     * @brief Usado para verificar se o cursor do mouse está sobre a superfície do botão
     * @param x Posição X do mouse
     * @param y Posição y do mouse
     * @returns true se mouse está acima, false caso constrário
     */
    bool isMouseHovering(int x, int y);
    /**
     * @brief Usado para verificar se o botão está ativo ou não (se já foi clicado)
     * @return true se botão já foi clicado, false caso contrário
     */
    bool isActive();
    /**
     * @brief Inverte o estado atual, usada para ativar ou desativar o botão
     */
    void switchActive();
    /**
     * @brief Desenha o botão na tela
     * @param x_offset A posição X do canto superior esquerdo do botão na tela
     * @param y_offset A posição Y do canto superior esquerdo do botão na tela
     * @param filled Usada para decidir se o botão será desenhado preenchido ou não
     * @note se filled for diferente de 0 ou 1, ele irá ser 0 por default
     */
    void draw(int x_offset, int y_offset, int filled);
    /**
     * @brief Desenha o botão na tela com uma mensagem centralizada
     * @param x_offset A posição X do canto superior esquerdo do botão na tela
     * @param y_offset A posição Y do canto superior esquerdo do botão na tela
     * @param filled Usada para decidir se o botão será desenhado preenchido ou não
     * @note se filled for diferente de 0 ou 1, ele irá ser 0 por default
     * @param message A mensagem que irá aparecer dentro do botão
     * @param cor_msg A cor da mensagem que irá aparecer dentro do botão
     */
    void draw(int x_offset, int y_offset, int filled, std::string message, ALLEGRO_COLOR cor_msg);
};

#endif