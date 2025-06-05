#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>

const float FPS = 30;              // Define FPS do Jogo
const int SCREEN_WIDTH = 800;      // Define o comprimento da janela do Jogo
const int SCREEN_LENGHT = 600;     // Define a largura da janela do jogo

// Define as fontes
const std::string ARIAL_FONT_PATH = "./assets/fonts/arial.ttf";
const int FONT_SIZE = 32;

//Define as imagens
const std::string BACKGROUND_IMG_PATH = "./assets/sprites/background-800-600.png";
const std::string BASE_IMG_PATH = "./assets/sprites/base-800-50.png";
const std::string BIRD_IMG_PATH = "./assets/sprites/yellowbird-midflap.png";

// Define os estados que o Jogo pode Estar
enum gameState{
    inStartMenu,
    inGame,
    inGameOver,
    inScoreBoard
};

int main(){
    ALLEGRO_DISPLAY *display = NULL;

    al_init();
    al_init_primitives_addon();
    display = al_create_display(SCREEN_WIDTH, SCREEN_LENGHT);

    return 0;
}