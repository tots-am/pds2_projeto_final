//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "db.hpp"
#include <cstdio>

const std::string arquivo_teste = "test_db.txt"; //declaração do arquivo a ser manuseado

void limparArquivo() {
    std::ofstream file(arquivo_teste, std::ios::trunc); //garante que arquivo está limpo
    file.close();
}
TEST_CASE("Test DB,CRUD") { //relativo à criação, leitura, update e delete do db
    limparArquivo();
    DB db(arquivo_teste);

    SUBCASE("Adicionar e ler registros") {
        db.adicionar("Tomas", 100); //teste do create
        db.adicionar("Vini", 150);
        db.adicionar("Isabela", 120);
        db.adicionar("Yuri", 140);
        db.adicionar("Gabriel", 90);

        auto registros = db.lerTodos();

        CHECK(registros.size() == 5);
        CHECK(registros[0].first == "Vini");   // confere ordenaçãeo dos dados
        CHECK(registros[0].second == 150);
        CHECK(registros[1].first == "Isabela");
        CHECK(registros[1].second == 120);
        CHECK(registros[2].first == "Tomas");
        CHECK(registros[2].second == 100); //so fiz os primeiros tres pela simplicidade 
    }
    SUBCASE("Buscar high score") {
        db.adicionar("Chaimo", 90);

        int score = db.buscarHighScore("Chaimo");
        CHECK(score == 90);

        int notFound = db.buscarHighScore("Desconhecido"); //chamando jogador nao presente no db
        CHECK(notFound == -1); //o programa deve retornar isso
    }
}