
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

constexpr int MAX_NAME_SIZE = 16;

const std::string DB_PATH = "./db/db.txt";

const std::string BACKGROUND_IMG_PATH = "./assets/sprites/background-800-600.png";
const std::string BASE_IMG_PATH = "./assets/sprites/base-800-50.png";

const std::string ARIAL_FONT_PATH = "./assets/fonts/arial.ttf";
constexpr int ARIAL_FONT_SIZE = 32;

const std::string FLAPPY_FONT_PATH = "./assets/fonts/flappy-font.fnt";
constexpr int FLAPPY_FONT_SIZE =32;

constexpr float FPS = 30;              // Define FPS do Jogo
constexpr int SCREEN_WIDTH = 800;      // Define o comprimento da janela do Jogo
constexpr int SCREEN_HEIGHT = 600;     // Define a largura da janela do jogo

#endif