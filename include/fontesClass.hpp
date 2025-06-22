#ifndef FONTESCLASS_HPP
#define FONTESCLASS_HPP
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h> //biblioteca de truetype fontes

/**
 * @class fontesClass
 * @brief Classe para gerenciar fontes usando Allegro.
 * 
 * Essa classe encapsula o carregamento e o uso de fontes TrueType (.ttf)
 * e fontes bitmap (.fnt) para desenho de texto na tela.
 */

class fontesClass{
    private:
        ALLEGRO_FONT* fonte_principal;
        int tam_fonte;
        ALLEGRO_FONT* fonte_principal; ///< Ponteiro para a fonte carregada
        int tam_fonte; ///< Tamanho da fonte (aplicável para TrueType)
    public:
        fontesClass(const char* caminho_fonte, int tam_fonte); //construtor com parametros(caminho do asset da fonte e tamanho da fonte)
        ~fontesClass(); //destrutor vazio 
    /**
     * @brief Construtor para carregar uma fonte TrueType.
     * @param caminho_fonte Caminho para o arquivo da fonte (.ttf).
     * @param tam_fonte Tamanho da fonte em pixels.
     * 
     * Inicializa a fonte principal carregando o arquivo especificado com o tamanho dado.
     */
        fontesClass(const char* caminho_fonte, int tam_fonte); 
    /**
     * @brief Construtor padrão.
     * 
     * Carrega uma fonte bitmap padrão (ex: flappy-font.fnt).
     * Deve-se garantir que o arquivo da fonte bitmap e sua imagem estejam disponíveis.
     */
        fontesClass();
        ~fontesClass();
    /**
     * @brief Desenha texto na tela usando a fonte carregada.
     * @param texto Texto a ser desenhado.
     * @param x Coordenada X para o texto.
     * @param y Coordenada Y para o texto.
     * @param cor Cor do texto (ALLEGRO_COLOR).
     * @param alinhamento Alinhamento do texto (padrão é ALLEGRO_ALIGN_CENTER).
     * 
     * Método que encapsula a chamada a al_draw_text para desenhar na tela.
     */
        void escrever(const std:: string& texto, float x, float y, ALLEGRO_COLOR cor, int alinhamento = ALLEGRO_ALIGN_CENTER); //função que descreve como deve-se utilizar a fonte
        //parametros(texto, coordenada x, coordenada y, cor, alinhamento)
        ALLEGRO_FONT* getfonte() const; //

    /**
    * @brief Retorna o ponteiro para a fonte carregada.
    * @return Ponteiro para ALLEGRO_FONT.
    */
        ALLEGRO_FONT* getfonte() const; 
};

#endif 