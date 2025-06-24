//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "canos.hpp"
#include "constants.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

TEST_CASE("Testa construção de Canos") {
    // Inicializa Allegro e Allegro Image (obrigatório para usar al_load_bitmap)
    al_init();
    al_init_image_addon();

    // Cria uma imagem fake (vazia, mas válida) para evitar falha no construtor
    ALLEGRO_BITMAP* dummy = al_create_bitmap(10, 10);
    CHECK(dummy != nullptr);  // Garante que a criação da imagem funcionou


    // Temporariamente intercepta os carregamentos de imagem
    auto old_load_bitmap = al_load_bitmap;
    al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);  // evita erro de display

    // Testa construção
    Canos c(100, 0);

    // Verificações básicas
    CHECK(c.get_x() >= 100);
    CHECK(c.get_altura_cima() >= 50);
    CHECK(c.get_altura_baixo() > 0);
    CHECK(c.get_largura() > 0);

    al_destroy_bitmap(dummy);  // Libera a imagem
}
