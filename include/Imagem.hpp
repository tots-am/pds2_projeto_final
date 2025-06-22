#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>

using namespace std;

class Imagem{  
    public:
      ALLEGRO_BITMAP * imagem;
      const string path;
      int largura;
      int altura;

      Imagem();
      Imagem(const string img_path);
      ~Imagem();
      void exibir(float pos_x, float pos_y);
      bool isLoaded();
};