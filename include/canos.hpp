#ifndef CANOS_HPP
#define CANOS_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <string> 

using namespace std; 

/**
 * @class Canos
 * @brief Gerencia a criação, desenho e atualização dos canos no jogo.
 *
 * A classe Canos é responsável por controlar a lógica de geração e movimento
 * dos obstáculos (canos) que o pássaro deve desviar. Ela mantém o estado
 * de cada cano, incluindo sua posição e altura, e gerencia sua reciclagem
 * na tela para simular um fluxo contínuo.
 */
class Canos {
    
private:
    int x;                          ///< Posição x inicial do cano
    int altura_cima;                ///< "Tamanho" (altura) do cano de cima
    int altura_baixo;               ///< "Tamanho" (altura) do cano de baixo
    int largura;                    ///< Largura de cada cano
    int tamanho_buraco;             ///< Tamanho do espaço entre os canos - buraco, no qual o pássaro irá passar.
    float largura_sprite;
    static float VELOCIDADE_CANO;

   ALLEGRO_BITMAP* canoCima;
   ALLEGRO_BITMAP* canoBaixo;


public:
    /**
     * @brief Construtor da classe Canos.
     * @param canoCimaPath Caminho para o arquivo de imagem do cano de cima.
     * @param canoBaixoPath Caminho para o arquivo de imagem do cano de baixo.
     * @param pos_x Posição X inicial do cano.
     * @param index Índice do cano na array de canos (usado para espaçamento inicial).
     *
     * Inicializa um objeto Canos com os caminhos das imagens e suas posições iniciais.
     * Carrega os bitmaps das imagens e inicializa as dimensões dos canos.
     */
    Canos(int pos_x, int index, string cano_cima_path, string cano_baixo_path);

    /**
     * @brief Construtor padrão da classe Canos.
     *
     * Inicializa um objeto Canos com valores padrão. Utilizado principalmente
     * para inicialização de arrays de objetos Canos antes da atribuição de valores.
     */
    Canos();

    /**
     * @brief Destrutor da classe Canos.
     *
     * Libera a memória alocada para os bitmaps dos canos.
     */
    ~Canos();

    /**
     * @brief Inicializa a posição e altura dos canos.
     * @param posX Posição X base para o conjunto de canos.
     * @param index Índice do cano na array, usado para calcular o espaçamento.
     *
     * Este método é chamado para configurar a posição horizontal e as alturas
     * aleatórias para o cano de cima e de baixo, garantindo o espaço para o pássaro passar.
     */
    void inicializarCanos(int posX, int index); 

    /**
     * @brief Desenha os canos na tela.
     *
     * Utiliza os bitmaps carregados para desenhar o cano de cima e o cano de baixo
     * em suas posições e dimensões atuais.
     */
    void desenhar();

    /**
     * @brief Atualiza a posição dos canos na tela e os recicla.
     *
     * Move os canos horizontalmente para a esquerda. Se um cano sair da tela,
     * ele é reposicionado no final da fila com novas alturas aleatórias,
     * criando um efeito de rolagem contínua.
     */
    void atualizar(Canos* canos, int numCanos, double deltaTime, float tempo);


    /**
      * @brief Reinicia a posição dos canos depois de GameOver
      * @return Void
      */

    void reset_position(Canos* canos, int numCanos);

    // Métodos Getters

    /**
     * @brief Retorna a posição X do cano.
     * @return A coordenada X do cano.
     */

    int get_x() const;

    /**
     * @brief Retorna a altura do cano de cima.
     * @return A altura do cano superior.
     */
    int get_altura_cima() const;

    /**
     * @brief Retorna a altura do cano de baixo.
     * @return A altura do cano inferior.
     */
    int get_altura_baixo() const;

    /**
     * @brief Retorna a largura do cano.
     * @return A largura de um cano.
     */
    int get_largura() const;
    /**
     * @brief Retorna a posição y do cano baixo
     */
    int get_y_baixo() const; // Posição Y do topo do cano de baixo
};

#endif