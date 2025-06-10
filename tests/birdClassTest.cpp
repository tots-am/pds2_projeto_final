#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "birdClass.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


struct AllegroInit {

    AllegroInit() {
        CHECK(al_init());
        CHECK(al_init_image_addon());
    }

};

TEST_SUITE("Bird Class Test"){

    TEST_CASE_FIXTURE(AllegroInit, "Create Image Test"){
        Bird passarinho(100, 150, "assets/sprites/yellowbird-midflap.png");

        CHECK(passarinho.get_bitmap());
        CHECK(passarinho.get_pos_x() == 100);
        CHECK(passarinho.get_pos_y() == 150);
    };

    TEST_CASE_FIXTURE(AllegroInit, "Create False Image Test"){
        Bird passarinho(100, 150, "falsocaminho.png");

        CHECK(passarinho.get_bitmap() == nullptr);
    }



}