#include "Imagem.hpp"

using namespace std;

int Imagem :: IniciaImagens(){
    if(!al_init_image_addon()){
        std::cout << "Falha ao iniciar pacote de imagens do Allegro" << std::endl;
        return -1;
    }
}

int Imagem :: CarregaImagens(){
    background = al_load_bitmap(BACKGROUND_IMG_PATH.c_str());
    if(background == nullptr){
        std::cout << "Falha ao carregar background" << std::endl;
        return -1;
    }

    base = al_load_bitmap(BASE_IMG_PATH.c_str());
    if(base == nullptr){
        std::cout << "Falha ao carregar base" << std::endl;
        return -1;
    }

    bird = al_load_bitmap(BIRD_IMG_PATH.c_str());
    if(bird == nullptr){
        std::cout << "Falha ao carregar passaro" << std::endl;
        return -1;
    }
}

void Imagem :: DesenhaBackground(){
    al_draw_bitmap(background, 0, 0, 0);
}

void Imagem :: DesenhaBase(){
    al_draw_bitmap(base, 0, 550, 0);
}

void Imagem :: DesenhaBird(float posY){
    al_draw_bitmap(bird, 200 , posY, 0);
}

void Imagem :: DestroiImagens(){
    al_destroy_bitmap(background);
    al_destroy_bitmap(base);
    al_destroy_bitmap(bird);
}