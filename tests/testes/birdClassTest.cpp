#include "doctest.h"
#include "birdClass.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "constants.hpp"

// g++ tests/birdClassTest.cpp src/birdClass.cpp -o meu_teste -Iinclude -lallegro -lallegro_main -lallegro_image

struct AllegroInit {

    AllegroInit() {
        CHECK(al_init());
        CHECK(al_init_image_addon());
    }

};

TEST_SUITE("Bird Class Teste"){

    TEST_CASE_FIXTURE(AllegroInit, "Construtor Estado Inicial"){
        Bird p(100, 150, "../assets/sprites/bird_spritesheet.png");

        CHECK(p.get_bitmap());
        CHECK(p.get_pos_x() == 100);
        CHECK(p.get_pos_y() == 150);
    };

    TEST_CASE_FIXTURE(AllegroInit, "Construtor Padrão"){
        Bird p;

        CHECK(p.get_bitmap() == nullptr);
        CHECK(p.get_pos_x() == 0);
        CHECK(p.get_pos_y() == 0);
        CHECK(p.get_vel_y() == 0);
        CHECK(p.get_path() == "");
        CHECK(p.getCor() == Yellow);

    };

    TEST_CASE_FIXTURE(AllegroInit, "Gravidade isolada - Posição e Velocidade"){
        Bird p(100, 150, "../assets/sprites/bird_spritesheet.png");
        
        float delta_time = 1.0f / 30.0f;


        for(int i = 0; i < 10; i++){
            float pos_inicial = p.get_pos_y();
            float vel_inicial = p.get_vel_y();
            p.update_position(delta_time);

            CHECK(p.get_pos_y() > pos_inicial);
            CHECK(p.get_vel_y() > vel_inicial);
        }
    }

    TEST_CASE_FIXTURE(AllegroInit, "Jump - Velocidade"){
        Bird p(100, 150, "../assets/sprites/bird_spritesheet.png");
        float delta_time = 1.0f / 30.0f;

        REQUIRE(p.get_vel_y() == 0);

        for(int i = 0; i < 10; i++){
            p.jump();
            p.update_position(delta_time);

            CHECK(p.get_vel_y() == JUMPSPEED);

        }
    }

    TEST_CASE_FIXTURE(AllegroInit, "Teste SETCOLOR") {
        Bird p;

        p.setCor(Red);
        CHECK(p.getCor() == Red);
        
        p.setCor(Yellow);
        CHECK(p.getCor() == Yellow);

        p.setCor(Blue);
        CHECK(p.getCor() == Blue);
    }

}