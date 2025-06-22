//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fontesClass.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

bool iniciar_al(){
    return al_init() && al_init_font_addon() && al_init_ttf_addon();
}
const char* caminho = "assets/fonts/arial.ttf";
TEST_CASE("Teste de inicialização da fontesClass"){
    fontesClass fonte(caminho, 32);
    CHECK(fonte.getfonte() != nullptr);
}
TEST_CASE("Carregamento de fonte bitmap .fnt") {
    CHECK(iniciar_al());
    fontesClass fonte;
    CHECK(fonte.getfonte() != nullptr);
}
TEST_CASE("Teste de escrever, sem recurso visual"){
    CHECK(iniciar_al());

    al_create_display(800,600);

    fontesClass fonte("assets/fonts/arial.ttf", 24);
    ALLEGRO_COLOR cor = al_map_rgb(255, 255, 255);

    CHECK_NOTHROW(fonte.escrever("Texto de Teste", 100, 100, cor, ALLEGRO_ALIGN_CENTER));

    al_destroy_display(al_get_current_display());
}

