#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "db.hpp"
#include <cstdio>

const std::string arquivo_teste = "test_db.txt"; //declaração do arquivo a ser manuseado

void limparArquivo() {
    std::ofstream file(arquivo_teste, std::ios::trunc); //garante que arquivo está limpo
    file.close();
}