#ifndef BIRD_CLASS_HPP
#define BIRD_CLASS_HPP
/// @file birdClass.hpp 

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

/**
 * @class Bird 
 * @brief Representa o personagem principal do jogo, controlado pelo jogador.
 * 
 * A classe é responsável por gerenciar sua própria simulação de física, a gravidade e o pulo, assim como se desenhar na tela e manter seu estado.
 */

class Bird{

    ALLEGRO_BITMAP *bird;
    float pos_x, pos_y;
    float largura_obj, altura_obj; 
    float vel_y;
    std::string BIRD_IMG_PATH;

    public:

    /**
     * @brief Construtor principal que cria o passáro em uma posição inicial definida.
     * 
     * @param pos_x_inicial Coordenada horizontal inicial
     * @param pos_y_inicial Coordenada vertical inicial
     * @param bird_img_path Caminho para o asset/bitmap.
     * @throw std::runtime_error caso o carregamento do bitmap do passáro falhar.
     */
    Bird(float pos_x_inicial, float pos_y_inicial, const std::string& bird_img_path);

    /**
     * @brief Construtor padrão
     * 
     * Construtor padrão que inicia todos os atributos como nulos (nullptr ou 0.0f)
     */
    Bird();

    /**
     * @brief Destrutor
     * 
     * Responsável por desalocar a memória do carregamento do BITMAP.
     * @note Possivelmente será retirado o carregamento do BITMAP após a implementação da classe de imagens.
     */
    ~Bird();

    
    /// @return Retorna a posição y centro do personagem.
    float get_pos_y() const;

    /// @return Retorna a posição x centro do personagem.
    float get_pos_x() const;

    /// @return Retorna a velocidade em pixels por frames.
    float get_vel_y() const;

    /**
     * @brief Verifica se o objeto está colidindo com as bordas verticais.
     * 
     * @return Retorna TRUE se em contato com a borda, FALSE caso contrário.
     * @note Ainda a ser implementado.
     */
    bool borda_hit() const;

    /// @return Retorna o caminho para o asset/bitmap. 
    std::string get_path() const;

    /// @brief Acesso ao recurso de bitmap do Allegro.
    /// @return Retorna o ponteiro para o bitmap carregado.
    ALLEGRO_BITMAP *get_bitmap() const;

    /**
     * @brief Aplica um impulso instantâneo no personagem
     * 
     * @note A velocidade em y é definida ao invés de adicionada a velocidade atual, o que mantém a consistencia e
     * previsibildiade dos pulos.
     */
    void jump();

    /**
     * @brief Aplica à velocidade atual uma alteração que simula a gravidade.
     * 
     * Essa função há o intuito de simular a gravidade, mas não só isso, também adicionar ao game feel utilizando 
     * um método de gravidade assimétrica. Essa representa diferentes gravidades ao subir, e ao descer. Também foi adicionado
     * uma especie de atrito que retira um pouco de velocidade a cada frame.
     * 
     * @see update()
     * @see jump()
     */
    void gravity();

    /// @brief Desenha o personagem relacionando o sprite e o centro(posições x e y)
    /// @note Não depende do tamanho do sprite, a função é capaz de desenhar a partir de qualquer carregamento.
    void draw();

    /**
     * @brief Faz o update da posiçao vertical do objeto, a partir da velocidade y calculada até o momento.
     * 
     * Também é responsável por definir as barreiras "físicas" do teto e chão que o personagem pode alcançar.
     * @warning O tamanho da tela está definido arbritariamente, isso deve mudar.
     */
    void update();

    /// @brief Desenha forçadamente o personagem em uma posição definida x e y.
    void forced_draw(float pox_x, float pos_y);

    /// @brief Diferente do update(), aqui pode-se atribuir a posição, inclusive horizontal do personagem.
    /// @see update()
    void reset_position(float pox_x, float pos_y);

};



#endif