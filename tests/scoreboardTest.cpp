//doctest para interfaces testaveis sem aspecto grafico
#include "doctest.h"
#include "scoreboard.hpp"
#include "db.hpp"
#include <cstdio>

const std::string arquivo_teste = "test_db.txt"; //declaração do arquivo a ser manuseado

void limparArquivo() { //para que possamos usar o mesmo arquivo teste de db, temos que garantir que ele esta limpo para independencia dos testes 
    std::ofstream file(arquivo_teste, std::ios::trunc); //garante que arquivo está limpo
    file.close();
}
TEST_CASE("Teste Scoreboard - Informação do jogador") {
    limparArquivo();

    ALLEGRO_FONT* fonte = nullptr;
    Scoreboard sb(fonte, fonte);

    //ta dando mjuito problema 