#include "birdClass.hpp"

Bird::Bird(float pos_x_inicial, float pos_y_inicial, const std::string &bird_img_path) : pos_x(pos_x_inicial), pos_y(pos_y_inicial),
BIRD_IMG_PATH(bird_img_path), bird(al_load_bitmap(bird_img_path.c_str())){
    if(!bird){
        std::cout << "Falha ao carregar passaro" << std::endl;
    }

    std::cout << "Passáro criado" << std::endl;
}


void Bird::draw(int pos_x, int pos_y){
    al_draw_bitmap(bird, pos_x, pos_y, 0);

}

float Bird::get_pos_x() const {
    return this-> pos_x;
}

float Bird::get_pos_y() const {
    return this-> pos_y;
}

ALLEGRO_BITMAP *Bird::get_bitmap() const {
    return this->bird;
}