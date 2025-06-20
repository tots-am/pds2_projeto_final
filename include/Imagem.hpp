#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using namespace std;

class Imagem{
    private:
      const std::string BACKGROUND_IMG_PATH = "./assets/sprites/background-800-600.png";
      const std::string BASE_IMG_PATH = "./assets/sprites/base-800-50.png";
      const std::string BIRD_IMG_PATH = "./assets/sprites/yellowbird-midflap.png";
      ALLEGRO_BITMAP * base;
      ALLEGRO_BITMAP * background;
      ALLEGRO_BITMAP * bird;

    public:
      int IniciaImagens();
      int CarregaImagens();
      void DesenhaBackground();
      void DesenhaBase();
      void DesenhaBird(float posY);
      void DestroiImagens();
};