#include "Imagem.hpp"
#include <exception>
using namespace std;

Imagem::Imagem() :
    imagem(nullptr),
    path(""),
    largura(0),altura(0)
{}

Imagem::Imagem(const string img_path) : 
    path(img_path)
{
    ALLEGRO_BITMAP * img = al_load_bitmap(img_path.c_str());
    if(img == nullptr){
        throw std::runtime_error("Erro ao carregar imagem");
    }
    this->imagem = img;
    this->largura = al_get_bitmap_width(imagem);
    this->altura = al_get_bitmap_height(imagem);
}

Imagem::~Imagem()
{
    al_destroy_bitmap(imagem);
}

void Imagem::exibir(float pos_x, float pos_y)
{
    al_draw_bitmap(imagem, pos_x, pos_y, 0);
}

bool Imagem::isLoaded(){
    if(this->imagem == nullptr){
        return false;
    } else {
        return true;
    }
}

float Imagem::getLargura() const {
    return al_get_bitmap_width(this->imagem);
}

float Imagem::getAltura() const {
    return al_get_bitmap_height(this->imagem);
}