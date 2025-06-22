#ifndef FONTESCLASS_HPP
#define FONTESCLASS_HPP

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

/**
 * @class fontesClass
 * @brief Classe para gerenciar fontes usando Allegro.
 * 
 * Essa classe encapsula o carregamento e o uso de fontes TrueType (.ttf)
 * e fontes bitmap (.fnt) para desenho de texto na tela.
 */
class fontesClass {
private:
    ALLEGRO_FONT* fonte_principal; ///< Ponteiro para a fonte carregada
    int tam_fonte;                 ///< Tamanho da fonte (aplicável para TrueType)

public:
    /**
     * @brief Construtor para carregar uma fonte TrueType.
     * @param caminho_fonte Caminho para o arquivo da fonte (.ttf).
     * @param tam_fonte Tamanho da fonte em pixels.
     */
    fontesClass(const char* caminho_fonte, int tam_fonte);

    /**
     * @brief Destrutor da classe. Libera a memória da fonte.
     */
    ~fontesClass();

    /**
     * @brief Desenha texto na tela usando a fonte carregada.
     * @param texto Texto a ser desenhado.
     * @param x Coordenada X.
     * @param y Coordenada Y.
     * @param cor Cor do texto.
     * @param alinhamento Alinhamento do texto (padrão: centro).
     */
    void escrever(const std::string& texto, float x, float y, ALLEGRO_COLOR cor, int alinhamento = ALLEGRO_ALIGN_CENTER);

    /**
     * @brief Retorna o ponteiro da fonte carregada.
     * @return ALLEGRO_FONT* fonte carregada.
     */
    ALLEGRO_FONT* getfonte() const;
};

#endif // FONTESCLASS_HPP