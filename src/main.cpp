#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>

const float FPS = 30;               // Define FPS do Jogo
const int SCREEN_WIDTH = 800;      // Define o comprimento da janela do Jogo
const int SCREEN_HEIGHT = 600;      // Define a largura da janela do jogo

// Define as fontes
const std::string ARIAL_FONT_PATH = "./assets/fonts/arial.ttf";
const int FONT_SIZE = 32;

//Define as imagens
const std::string BACKGROUND_IMG_PATH = "./assets/sprites/background-800-600.png";
const std::string BASE_IMG_PATH = "./assets/sprites/base-800-50.png";
const std::string BIRD_IMG_PATH = "./assets/sprites/yellowbird-midflap.png";

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

    //Inicializando objetos Allegro e Carregando Assets
    if (!al_init()) {
        std::cout << "Falha ao iniciar allegro" << std::endl;
        return -1;
    }

    // Iniciando Fontes
    if(!al_init_font_addon()){
        std::cout << "Falha ao iniciar pacote de fontes Allegro" << std::endl;
        return -1;
    }

    if(!al_init_ttf_addon()){
        std::cout << "Falha ao iniciar pacote de fontes ttf Allegro" << std::endl;
        return -1;
    }

    // Seção para carregar fontes
    ALLEGRO_FONT *font_arial = al_load_font(ARIAL_FONT_PATH.c_str(), FONT_SIZE, 0);
    if(font_arial == nullptr){
        std::cout << "Falha ao iniciar fonte" << std::endl;
        return -1;
    }

    // Iniciando imagens
    if(!al_init_image_addon()){
        std::cout << "Falha ao iniciar pacote de imagens do Allegro" << std::endl;
        return -1;
    }
    
    // Seção para carregar imagens
    ALLEGRO_BITMAP *background = al_load_bitmap(BACKGROUND_IMG_PATH.c_str());
    if(background == nullptr){
        std::cout << "Falha ao carregar background" << std::endl;
        return -1;
    }

    ALLEGRO_BITMAP *base = al_load_bitmap(BASE_IMG_PATH.c_str());
    if(base == nullptr){
        std::cout << "Falha ao carregar base" << std::endl;
        return -1;
    }

    ALLEGRO_BITMAP *bird = al_load_bitmap(BIRD_IMG_PATH.c_str());
    if(bird == nullptr){
        std::cout << "Falha ao carregar passaro" << std::endl;
        return -1;
    }

    // Iniciando Primitivas
    if (!al_init_primitives_addon()){
        std::cout << "Falha ao iniciar pacote de primitivas do Allegro" << std::endl;
        return -1;
    }

    // Instanciando fila de eventos
    eventQueue= al_create_event_queue();
    if (!eventQueue) {
        std::cout << "Falha ao iniciar fila de eventos" << std::endl;
        return -1;
    }

    // Iniciando teclado
    if (!al_install_keyboard()) {
        std::cout << "Falha ao iniciar teclado" << std::endl;
        return -1;
    }

    // Instanciando display
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if(!display){
        std::cout << "Falha ao criar display" << std::endl;
        return -1;
    }

    // Instanciando timer
    timer = al_create_timer(1.0/FPS);
    if(!timer){
        std::cout << "Falha ao Iniciar Timer" << std::endl;
        al_destroy_display(display);
        return -1;
    }

    // Especificar de onde pode vir os eventos
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());

    // Inicia o timer
    al_start_timer(timer);

    // Variaveis do Jogo
    bool endGame = false;               // Detecta se jogo acabou
    gameState state = inStartMenu;      // Tela Inicial do Jogo
    const float gravidade = 1;          // Gravidade

    // Variaveis do Bird
    const float posX = SCREEN_WIDTH/4;  // Posição do passaro em X
    float posY;                         // Posição do passaro em Y
    float velY;                         // Velocidade do passaro em Y
    const float jumpSpeed = 15;         // Velocidade do pulo do passaro
    bool jump = false;                  // Variavel se esta pulando ou nao

    // Loop principal
    while (!endGame)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);

        //Eventos que ocorrem em todo frame
        if(event.type == ALLEGRO_EVENT_TIMER){
            // Desenha o background
            al_draw_bitmap(background, 0, 0, 0);

            // Desenha a base
            al_draw_bitmap(base, 0, 550, 0);

            // Switch para escolher em qual tela do jogo o Usuario está
            switch (state)
            {
                case inStartMenu:
                    posY = (SCREEN_HEIGHT/2) + 10;
                    velY = 0;
                    al_draw_filled_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(255, 255, 255));
                    al_draw_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(0,0,0), 5);
                    al_draw_text(
                        font_arial, 
                        al_map_rgb(0,0,0), 
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - FONT_SIZE, 
                        ALLEGRO_ALIGN_CENTER, 
                        "Bem vindo ao Jogo!"
                    );
                    al_draw_text(
                        font_arial, 
                        al_map_rgb(0,0,0), 
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 + FONT_SIZE/2, 
                        ALLEGRO_ALIGN_CENTER, 
                        "Aperte ENTER para começar"
                    );
                    break;

                case inGame:
                    break;

                case inGameOver:
                    break;

                case inScoreBoard:
                    break;
            }
        }

        al_flip_display();
    }
    
    return 0;
}