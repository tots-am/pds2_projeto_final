#ifndef FONTES_TAD_HPP
#define FONTES_TAD_HPP

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h> //biblioteca de truetype fontes

class fontesClass{
    private:
        ALLEGRO_FONT* fonte_principal;
        int tam_fonte;
    public:
        fontesClass(const char* caminho_fonte, int tam_fonte); //construtor com parametros(caminho do asset da fonte e tamanho da fonte)
        ~fontesClass(); //destrutor vazio 
        void escrever(const std:: string& texto, float x, float y, ALLEGRO_COLOR cor, int alinhamento = ALLEGRO_ALIGN_CENTER); //função que descreve como deve-se utilizar a fonte
        //parametros(texto, coordenada x, coordenada y, cor, alinhamento)
        ALLEGRO_FONT* getfonte() const; //
};

#endif // FONTES_TAD_HPP