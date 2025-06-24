//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Imagem.hpp"
#include "constants.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

bool allegro_initialized = false;

void setup_allegro() {
    if (!allegro_initialized) {
        REQUIRE(al_init());
        REQUIRE(al_init_image_addon());
        allegro_initialized = true;
    }
}

TEST_CASE("Imagem default constructor") {
    setup_allegro();

    Imagem img;

    CHECK(img.imagem == nullptr);
    CHECK(img.path == "");
    CHECK(img.largura == 0);
    CHECK(img.altura == 0);
    CHECK(img.isLoaded() == false);
}

TEST_CASE("Imagem com caminho inválido") {
    setup_allegro();

    Imagem img("caminho/invalido.png");

    CHECK(img.isLoaded() == false);
}

TEST_CASE("Imagem com caminho válido") {
    setup_allegro();

    const std::string caminho_valido = BASE_IMG_PATH;

    FILE* file = fopen(caminho_valido.c_str(), "r");
    if (!file) {
        std::string msg = "Imagem de teste não encontrada: " + caminho_valido;
        INFO(msg);
        WARN(false);
        return; 
    }
    fclose(file);

    Imagem img(caminho_valido);

    CHECK(img.isLoaded() == true);
    CHECK(img.getLargura() > 0);
    CHECK(img.getAltura() > 0);
}
