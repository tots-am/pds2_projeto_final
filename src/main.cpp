#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include "birdClass.hpp"
#include "fontesClass.hpp"

const float FPS = 30;               // Define FPS do Jogo
const int SCREEN_WIDTH = 800;      // Define o comprimento da janela do Jogo
const int SCREEN_HEIGHT = 600;     // Define a largura da janela do jogo

// Define as fontes
const std::string ARIAL_FONT_PATH = "./assets/fonts/arial.ttf";
const int FONT_SIZE = 32;
fontesClass fonteArial(ARIAL_FONT_PATH.c_str(), FONT_SIZE); // Instancia a classe de fontes com o caminho da fonte e o tamanho

const std::string FLAPPY_FONT_PATH = "./assets/fonts/flappy-font.fnt";
const int FLAPPY_FONT_SIZE =32;
fontesClass fonteFlappy(FLAPPY_FONT_PATH.c_str(), FLAPPY_FONT_SIZE); // Instancia a classe de fontes com o caminho da fonte e o tamanho
//Define as imagens
const std::string BACKGROUND_IMG_PATH = "./assets/sprites/background-800-600.png";
const std::string BASE_IMG_PATH = "./assets/sprites/base-800-50.png";

// Define as telas que o Jogo pode Estar
enum gameState{
    inStartMenu,
    inGame,
    inGameOver,
    inScoreBoard
};

int main(){
    // Iniciando objetos do Allegro
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *font_arial = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *base = NULL;

    //Inicializações das Funções da Biblioteca do Allegro
    if (!al_init()) {
        std::cout << "Falha ao iniciar allegro" << std::endl;
        return -1;
    }

    if(!al_init_font_addon()){
        std::cout << "Falha ao iniciar pacote de fontes Allegro" << std::endl;
        return -1;
    }

    if(!al_init_ttf_addon()){
        std::cout << "Falha ao iniciar pacote de fontes ttf Allegro" << std::endl;
        return -1;
    }

    // Seção para carregar fontes
    /*ALLEGRO_FONT *font_arial = al_load_font(ARIAL_FONT_PATH.c_str(), FONT_SIZE, 0);
    if(font_arial == nullptr){
        std::cout << "Falha ao iniciar fonte" << std::endl;
        return -1;
    }*/
    if(fonteArial.getfonte() == nullptr){
        std::cout << "Falha ao iniciar fonte" << std::endl;
        return -1;
    }
    if(fonteFlappy.getfonte() == nullptr){
        std::cout << "Falha ao iniciar fonte Flappy" << std::endl;
        return -1;
    }

    if(!al_init_image_addon()){
        std::cout << "Falha ao iniciar pacote de imagens do Allegro" << std::endl;
        return -1;
    }

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if(!display){
        std::cout << "Falha ao criar display" << std::endl;
        return -1;
    }

    eventQueue= al_create_event_queue();
    if (!eventQueue) {
        std::cout << "Falha ao iniciar fila de eventos" << std::endl;
        return -1;
    }

    timer = al_create_timer(1.0/FPS);
    if(!timer){
        std::cout << "Falha ao Iniciar Timer" << std::endl;
        al_destroy_display(display);
        return -1;
    }

    // Seção para carregar fontes
    font_arial = al_load_font(ARIAL_FONT_PATH.c_str(), FONT_SIZE, 0);
    if(font_arial == nullptr){
        std::cout << "Falha ao iniciar fonte" << std::endl;
        return -1;
    }
    
    // Seção para carregar imagens
    background = al_load_bitmap(BACKGROUND_IMG_PATH.c_str());
    if(background == nullptr){
        std::cout << "Falha ao carregar background" << std::endl;
        return -1;
    }

    base = al_load_bitmap(BASE_IMG_PATH.c_str());
    if(base == nullptr){
        std::cout << "Falha ao carregar base" << std::endl;
        return -1;
    }

    // Instanciando Entidades
    Bird bird((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);

    // Especificar de onde vem os eventos
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());

    // Variaveis do Jogo
    bool endGame = false;
    gameState state = inStartMenu;

    // Inicia o timer
    al_start_timer(timer);

    double last_time = al_get_time();

    while(!endGame){
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);
   
        //Eventos que acontecem em todo frame
        if(event.type == ALLEGRO_EVENT_TIMER){
            double current_time = al_get_time();
            double delta_time = current_time - last_time;
            last_time = current_time;
            
            al_clear_to_color(al_map_rgb(0,0,0));
            
            // Desenha o background
            al_draw_bitmap(background, 0, 0, 0);

            // Desenha a base
            al_draw_bitmap(base, 0, 550, 0);

            // Switch para escolher em qual tela do jogo o Usuario está e fazer as atualizações
            switch (state)
            {
                case inStartMenu:    
                    al_draw_filled_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(255, 165, 0));
                    al_draw_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(253,253,150), 5);
                    fonteFlappy.escrever(
                        "FLAPPY BIRD",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - FONT_SIZE, 
                        al_map_rgb(0,0,0),
                        ALLEGRO_ALIGN_CENTER
                    );
                    fonteArial.escrever(
                        "Aperte ENTER para começar",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 + FONT_SIZE/2, 
                        al_map_rgb(255,255,255), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    break;
                
                case inGame:
                    if(!bird.borda_hit()){
                        bird.update_position(delta_time);
                    } else {
                        state = inGameOver;
                    }
                    bird.draw();
                    break;
                
                case inGameOver:
                    al_draw_filled_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(255, 165, 0));
                    al_draw_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(253,253,253), 5);
                    fonteFlappy.escrever(
                        "GAME OVER",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - FONT_SIZE/2, 
                        al_map_rgb(0,0,0), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    fonteArial.escrever(
                        "Aperte ENTER para recomeçar",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 + FONT_SIZE/2, 
                        al_map_rgb(0,0,0), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    
                    bird.draw();
                    break;
                
                case inScoreBoard:
                    break;
            }

            al_flip_display();
        }

        //Eventos que acontecem quando uma tecla é apertada
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_SPACE:
                    if(state == inGame){
                        bird.jump();
                    }
                    break;
                
                case ALLEGRO_KEY_ENTER:
                    if(state == inGameOver){
                        bird.reset_position((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
                        state = inStartMenu;
                    } 

                    else if(state == inStartMenu){
                        state = inGame;
                    }
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    endGame = true;
                    break;
            }
        }

        //Sair quando usuario aperta o X-inho
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            endGame = true;
        }
    }

    al_destroy_bitmap(background);
    al_destroy_bitmap(base);
    al_destroy_timer(timer);
    al_destroy_event_queue(eventQueue);
    al_destroy_display(display);

    return 0;
}