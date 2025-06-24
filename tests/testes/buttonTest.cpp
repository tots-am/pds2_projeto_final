//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "button.hpp"

//simulando dependencias graficas
ALLEGRO_COLOR cor = al_map_rgb(255,255,255); //cor branca
ALLEGRO_FONT *fonte = nullptr;

TEST_CASE("Testando classe geral"){
    Button button(100, 200, fonte, cor);

    SUBCASE("Testando hover do mouse"){// testando função isHovering que retorna bool 
        button.draw(50,50,0);
        CHECK(button.isMouseHovering(100,100) == true); // o mouse está em cima do botao 
        CHECK(button.isMouseHovering(10,10) == false); // o mouse nao está em cima do botao
    }
    SUBCASE("Testando ativação do botao"){ //testando função isActive e swtichActive
        CHECK(button.isActive() ==  false); //botao começa inativo
        button.switchActive(); //ativa botao
        CHECK(button.isActive == true); //botao deve estar ativo
        button.switchActive(); //desativa botao ligado
        CHECK(button.isActive() == false); //botao deve estar desativado
    }
    SUBCASE("Testando funções relativas à cor"){ //get_cor e ser_cor
        ALLEGRO_COLOR cor2 = al_map_rgb(255,0,0); //cor vermelha
        button.set_cor(cor2); //uma nova cor
        ALLEGRO_COLOR cor_agora = button.get_cor; //indica a cor atual do botao
        CHECK(cor_agora.r == doctest::Approx(cor2.r));
        CHECK(cor_agora.g == doctest::Approx(cor2.g));
        CHECK(cor_agora.b == doctest::Approx(cor2.b));
    }
}
