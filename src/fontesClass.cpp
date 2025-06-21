#include <iostream>
#include "fontesClass.hpp"

using namespace std;

//construtor
fontesClass::fontesClass(const char* caminho_fonte, int tam_fonte) : tam_fonte(tam_fonte){
    fonte_principal = al_load_font(caminho_fonte, tam_fonte, 0); //al_load_font tem parametros(caminho, tamanho e flags) e faz o carregamento da fonte
    if(fonte_principal == nullptr){ //confere se carregou corretamente
        cout << "Falha ao carregar fonte: " << caminho_fonte << endl;
    }
}
fontesClass::fontesClass(){
    fonte_principal = al_load_bitmap_font("flappy-font.fnt");
    if(fonte_principal == nullptr){ //confere se carregou corretamente
        cout << "Falha ao carregar fonte flappy-font" << endl;
    }
}
//conferir como seria o construtor de uma fonte bitmap

//destrutor
fontesClass::~fontesClass(){
    if(fonte_principal) {
        al_destroy_font(fonte_principal); //destrói a fonte
    }
}
//escrever - função que substitui al_draw_text
void fontesClass::escrever(const std::string& texto, float x, float y, ALLEGRO_COLOR cor, int alinhamento){
    if(fonte_principal){
        al_draw_text(fonte_principal, cor, x, y, alinhamento, texto.c_str()); //texto.c_str() converte string para const char* já que allegro nao reconhece string
    }
}

//fonte
ALLEGRO_FONT* fontesClass:: getfonte() const{
    return fonte_principal; 
}
