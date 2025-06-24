#include "doctest.h"

#include "canos.hpp"
#include "constants.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

TEST_CASE("Testa construção de Canos e getters") {
    al_init();                  // Inicializa Allegro
    al_init_image_addon();     // Inicializa addon de imagens

    Canos c1(SCREEN_WIDTH, 0);

    CHECK(c1.get_x() >= SCREEN_WIDTH); // x deve ser maior ou igual à tela
    CHECK(c1.get_altura_cima() >= 50);
    CHECK(c1.get_altura_cima() <= 250);
    CHECK(c1.get_largura() > 0);
    CHECK(c1.get_altura_baixo() > 0);
    CHECK(c1.get_y_baixo() == c1.get_altura_cima() + TAMANHO_BURACO_CANOS);
}

TEST_CASE("Testa reset_position dos canos") {
    al_init();
    al_init_image_addon();

    const int numCanos = 3;
    Canos* canos = new Canos[numCanos]{
        Canos(SCREEN_WIDTH, 0),
        Canos(SCREEN_WIDTH, 1),
        Canos(SCREEN_WIDTH, 2)
    };

    canos[0].reset_position(canos, numCanos);

    for (int i = 0; i < numCanos; i++) {
        CHECK(canos[i].get_x() == SCREEN_WIDTH + (i * ESPACO_ENTRE_OS_CANOS));
        CHECK(canos[i].get_y_baixo() == canos[i].get_altura_cima() + TAMANHO_BURACO_CANOS);
    }

    delete[] canos;
}

TEST_CASE("Testa atualização da posição dos canos") {
    al_init();
    al_init_image_addon();

    const int numCanos = 2;
    Canos* canos = new Canos[numCanos]{
        Canos(SCREEN_WIDTH, 0),
        Canos(SCREEN_WIDTH, 1)
    };

    float tempoInicial = 0.0;
    double deltaTime = 0.1;

    int x_anterior = canos[0].get_x();
    canos[0].atualizar(canos, numCanos, deltaTime, tempoInicial);
    int x_atual = canos[0].get_x();

    CHECK(x_atual < x_anterior); // Deve ter andado para a esquerda

    delete[] canos;
}

