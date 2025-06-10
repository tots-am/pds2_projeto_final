#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "birdClass.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// g++ tests/birdClassTest.cpp src/birdClass.cpp -o meu_teste -Iinclude -lallegro -lallegro_main -lallegro_image

struct AllegroInit {

    AllegroInit() {
        CHECK(al_init());
        CHECK(al_init_image_addon());
    }

};

TEST_SUITE("Bird Class Test"){

    TEST_CASE_FIXTURE(AllegroInit, "Create Image Test"){
        Bird p(100, 150, "assets/sprites/yellowbird-midflap.png");

        CHECK(p.get_bitmap());
        CHECK(p.get_pos_x() == 100);
        CHECK(p.get_pos_y() == 150);
    };

    TEST_CASE_FIXTURE(AllegroInit, "Create False Image Test"){

        std::string caminho = "caminho_invalido";
        CHECK_THROWS_AS(Bird(100, 150, caminho), const std::runtime_error&);
    };

    TEST_CASE_FIXTURE(AllegroInit, "Update axis"){
        Bird p(100, 150, "assets/sprites/yellowbird-midflap.png");
        
        p.update(105.0, 200);

        CHECK(p.get_pos_x() == 105.0);
        CHECK(p.get_pos_y() == 200);
    }



}