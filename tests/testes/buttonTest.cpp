#include "doctest.h"
#include "button.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// Inicialização de Allegro e carregamento da fonte
void setup_allegro_button_test() {
    static bool initialized = false;
    if (!initialized) {
        REQUIRE(al_init());
        REQUIRE(al_init_font_addon());
        REQUIRE(al_init_ttf_addon());
        REQUIRE(al_init_primitives_addon());
        initialized = true;
    }
}

TEST_CASE("Testando classe geral") {
    setup_allegro_button_test();
    ALLEGRO_DISPLAY *display = al_create_display(800, 600);
    REQUIRE_MESSAGE(display != nullptr, "Falha ao criar display Allegro");

    ALLEGRO_COLOR cor = al_map_rgb(255, 255, 255); // cor branca
    ALLEGRO_FONT* fonte = al_create_builtin_font();
    REQUIRE_MESSAGE(fonte != nullptr, "Falha ao criar fonte interna");

    Button button(50, 100, fonte, cor);

    SUBCASE("Testando hover do mouse") {
        button.draw(0, 0, 0);  // Necessário para definir x1, y1, x2, y2
        CHECK(button.isMouseHovering(10, 10) == true);     // Dentro do botão
        CHECK(button.isMouseHovering(300, 300) == false);  // Fora do botão
    }

    SUBCASE("Testando ativação do botão") {
        CHECK(button.isActive() == false);  // Inicialmente inativo
        button.switchActive();
        CHECK(button.isActive() == true);
        button.switchActive();
        CHECK(button.isActive() == false);
    }

    SUBCASE("Testando funções relativas à cor") {
        ALLEGRO_COLOR cor2 = al_map_rgb(255, 0, 0); // vermelho
        button.set_cor(cor2);
        ALLEGRO_COLOR cor_atual = button.get_cor();
        CHECK(cor_atual.r == doctest::Approx(cor2.r));
        CHECK(cor_atual.g == doctest::Approx(cor2.g));
        CHECK(cor_atual.b == doctest::Approx(cor2.b));
    }

    al_destroy_font(fonte);
    al_destroy_display(display);
}
