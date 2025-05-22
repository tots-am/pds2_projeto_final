#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <unistd.h>
#include <iostream>

const float FPS = 30;              // Define FPS do Jogo
const int SCREEN_WIDTH = 800;      // Define o comprimento da janela do Jogo
const int SCREEN_LENGHT = 600;     // Define a largura da janela do jogo

int main(int argc, char **argv){
    ALLEGRO_DISPLAY *display = NULL;

    al_init();
    al_init_primitives_addon();
    display = al_create_display(SCREEN_WIDTH, SCREEN_LENGHT);

    return 0;
}