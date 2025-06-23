#ifndef IMAGEM_H
#define IMAGEM_H
  ///@file Imagem.hpp

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using namespace std;

/**
 * @class Imagem
 * @brief Classe responsável por carregar, exibir e gerenciar imagens.
 */
class Imagem {
public:
    ALLEGRO_BITMAP* imagem;
    const string path;
    int largura;
    int altura;

    /**
     * @brief Construtor padrão. Não carrega nenhuma imagem.
     */
    Imagem();

    /**
     * @brief Construtor que carrega uma imagem a partir do caminho especificado.
     * @param img_path Caminho para o arquivo de imagem.
     */
    Imagem(const string img_path);

    /**
     * @brief Destrutor. Libera a memória associada à imagem carregada.
     */
    ~Imagem();

    /**
     * @brief Exibe a imagem na posição especificada.
     * @param pos_x Posição X onde a imagem será desenhada.
     * @param pos_y Posição Y onde a imagem será desenhada.
     */
    void exibir(float pos_x, float pos_y);

    /**
     * @brief Verifica se a imagem foi carregada com sucesso.
     * @return true se a imagem foi carregada corretamente, false caso contrário.
     */
    bool isLoaded();

    /**
     * @brief Obtém a altura da imagem.
     * @return Altura da imagem em pixels.
     */
    float getAltura() const;

    /**
     * @brief Obtém a largura da imagem.
     * @return Largura da imagem em pixels.
     */
    float getLargura() const;
};

#endif
