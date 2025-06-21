#DEFINE DOCTEST_CONFIG_IMPLEMET_WITH_MAIN
#include "doctest.h"
#include "fontesClass.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

bool iniciar_al(){
    return al_init() && al_init_font_addon() && al_init_ttf_addon();
}
TEST_CASE("Teste de inicialização da fontesClass"){
    CHECK(iniciar_al());

    const char* caminho = "assets/fonts/arial.ttf";
    int tam = 20;

    fontesClass fonte(caminho, tam);
    CHECK(fonte.getfonte() != nullptr);
}
