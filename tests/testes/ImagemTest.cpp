
#include "doctest.h"
#include "Imagem.hpp"
#include "constants.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

bool allegro_initialized = false;

void setup_allegro_image_test() {
    static bool initialized = false;
    if (!initialized) {
        REQUIRE(al_init());
        REQUIRE(al_init_image_addon());
        initialized = true;
    }
}

TEST_CASE("Imagem default constructor") {
    setup_allegro_image_test();

    SUBCASE("Construtor Padrão") {
        Imagem img;

        CHECK(img.imagem == nullptr);
        CHECK(img.path == "");
        CHECK(img.largura == 0);
        CHECK(img.altura == 0);
        CHECK(img.isLoaded() == false);
    }

    SUBCASE("Imagem com caminho inválido"){
        CHECK_THROWS_AS(Imagem img("caminho/invalido.png"), std::runtime_error);
    }

    SUBCASE("Imagem com caminho válido"){
        const std::string caminho_valido = BASE_IMG_PATH;

        FILE* file = fopen(caminho_valido.c_str(), "r");
        if (!file) {
            std::string msg = "Imagem de teste não encontrada: " + caminho_valido;
            INFO(msg);
            return; 
        }
        fclose(file);

        Imagem img(caminho_valido);

        CHECK(img.isLoaded() == true);
        CHECK(img.getLargura() > 0);
        CHECK(img.getAltura() > 0);
    }

}