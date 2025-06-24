//doctest para interfaces testaveis sem aspecto grafico
#include "doctest.h"
#include "scoreboard.hpp"
#include "db.hpp"
#include <cstdio>

void setup_allegro_scoreboard_test() {
    static bool initialized = false;
    if (!initialized) {
        REQUIRE(al_init());
        REQUIRE(al_init_font_addon());
        REQUIRE(al_init_ttf_addon());
        REQUIRE(al_init_primitives_addon());
        initialized = true;
    }
}

const std::string arquivo_teste = "test_db.txt"; //declaração do arquivo a ser manuseado

void limparDB() { 
    std::ofstream file(arquivo_teste, std::ios::trunc); //garante que arquivo está limpo
    file.close();
}
TEST_CASE("Teste Scoreboard - Informação do jogador") {
    limparDB();
    setup_allegro_scoreboard_test();

    ALLEGRO_DISPLAY *display = al_create_display(800, 600);
    REQUIRE_MESSAGE(display != nullptr, "Falha ao criar display Allegro");

    ALLEGRO_FONT* fonte = al_create_builtin_font();
    Scoreboard sb(fonte, fonte, arquivo_teste);

    SUBCASE("Funcão draw"){
        sb.drawScoreboard();
    }
    SUBCASE("Função exibirInfo"){
        sb.exibeInfos();
    }
    SUBCASE("Função UpdatePlayerInfo"){
        std::string name = "tomas";
        int pontos = 10;
        DB db_teste(arquivo_teste);

        sb.updatePlayerInfo(name, pontos);

        auto registros = db_teste.lerTodos();
        CHECK(registros[0].first == name);
        CHECK(registros[0].second == pontos);
    }
    limparDB();
    al_destroy_font(fonte);
    al_destroy_display(display);
}