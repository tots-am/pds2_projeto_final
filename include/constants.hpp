///@file constants.hpp
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

// Tamanho maximo que o nome do jogador pode ter
constexpr int MAX_NAME_SIZE = 16;

// Caminhos
  // Assets
    const std::string PIPE1_IMG_PATH = "./assets/sprites/pipe-green.png";
    const std::string PIPE2_IMG_PATH = "./assets/sprites/pipe-green-down.png";
    const std::string TITLE_IMG_PATH = "./assets/sprites/title.png";
    const std::string GAMEOVER_IMG_PATH = "./assets/sprites/gameover.png";
    const std::string BACKGROUND_IMG_PATH = "./assets/sprites/background-800-600.png";
    const std::string BASE_IMG_PATH = "./assets/sprites/base-800-50.png";
    const std::string BIRD_SPRITESHEET_PATH = "./assets/sprites/bird_spritesheet.png";
  // Db
    const std::string DB_PATH = "./db/db.txt";
// Cores
const ALLEGRO_COLOR BLACK = al_map_rgb(0,0,0);
const ALLEGRO_COLOR WHITE = al_map_rgb(255,255,255);
const ALLEGRO_COLOR ORANGE = al_map_rgb(255, 165, 0);
const ALLEGRO_COLOR PASTEL_WHITE = al_map_rgb(253,253,150);
const ALLEGRO_COLOR LIGHT_GREY = al_map_rgb(192, 192, 192);

// Fontes
const std::string ARIAL_FONT_PATH = "./assets/fonts/arial.ttf";
constexpr int ARIAL_FONT_SIZE = 32;

const std::string FLAPPY_FONT_PATH = "assets/fonts/flappy-font.ttf";
constexpr int FLAPPY_FONT_SIZE = 60;

const std:: string PIXELIFY_FONT_PATH = "assets/fonts/PixelifySans-Regular.ttf";
constexpr int PIXELIFY_FONT_SIZE = 32;

// Configurações do Jogo
constexpr float FPS = 30;                    // Define FPS do Jogo
constexpr int SCREEN_WIDTH = 800;            // Define o comprimento da janela do Jogo (pixels)
constexpr int SCREEN_HEIGHT = 600;           // Define a largura da janela do jogo (pixels)
const int ALTURA_BASE = 50;                  // Altura da base (pixels)
constexpr int NUM_CANOS = 4;                 // Numero de canos renderizados simultaneamente
constexpr int ESPACO_ENTRE_OS_CANOS = 250;   // Espaço entre os Canos (pixels)
constexpr int TAMANHO_BURACO_CANOS = 200;    // Tamanho do buraco entre o cano superior e inferior (pixels)
const float GRAVIDADE = 800.0f;              // Define a aceleração da gravidade
const float JUMPSPEED = -350.0f;             // Define a velocidade instantanea ao pular
static constexpr float FATOR_DIFICULDADE = 0.84f; //Aumenta a velocidade dos canos

#endif