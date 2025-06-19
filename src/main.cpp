#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include "../include/Canos.hpp";
#include "../include/Constante.hpp";

const float FPS = 30;               // Define FPS do Jogo
const int SCREEN_WIDTH = 800;      // Define o comprimento da janela do Jogo
const int SCREEN_HEIGHT = 600;      // Define a largura da janela do jogo
const int ALTURA_BASE = 50;

#define NUM_CANOS 4 //numero de canos na tela
#define VELOCIDADE_CANO 3
#define ESPACO_ENTRE_OS_CANOS 250 //distância horizontal entre os canos

class Canos {
    public:
    int x = 0;
    int altura_cima = 0;
    int altura_baixo = 0;
    int largura = 100;
    int tamanho_buraco = 250;

    void inicializarCanos(int posX, int index){
        x = posX + (index * ESPACO_ENTRE_OS_CANOS);
        altura_cima = rand() % 200 + 50;
        largura = 100;
        altura_baixo = SCREEN_HEIGHT - altura_cima - tamanho_buraco - ALTURA_BASE;
    }

    void desenhar(ALLEGRO_BITMAP* canoCima, ALLEGRO_BITMAP* canoBaixo){
        al_draw_scaled_bitmap(canoCima, 0, 0, largura, al_get_bitmap_height(canoCima), x, 0, largura, altura_cima, 0);
        al_draw_scaled_bitmap(canoBaixo, 0, 0, largura, al_get_bitmap_height(canoBaixo), x, altura_cima + tamanho_buraco, largura, altura_baixo, 0);


    }

    void atualizar(Canos canos[]){
        for(int i = 0; i < NUM_CANOS; i++){
            canos[i].x -= VELOCIDADE_CANO;
            if(canos[i].x < - canos[i].largura){
                int ultimoCano = (i == 0) ? NUM_CANOS - 1 : i - 1;
                canos[i].x = canos[ultimoCano].x + ESPACO_ENTRE_OS_CANOS;
                canos[i].altura_cima = rand() % 200 + 50;
                canos[i].altura_baixo = SCREEN_HEIGHT - canos[i].altura_cima - tamanho_buraco - ALTURA_BASE;
            }
        }
    }
};

Canos canos[NUM_CANOS];

// Define as fontes
const std::string ARIAL_FONT_PATH = "./assets/fonts/arial.ttf";
const int FONT_SIZE = 32;

//Define as imagens
const std::string BACKGROUND_IMG_PATH = "./assets/sprites/background-800-600.png";
const std::string BASE_IMG_PATH = "./assets/sprites/base-800-50.png";
const std::string BIRD_IMG_PATH = "./assets/sprites/yellowbird-midflap.png";
const std::string PIPEDOWN_IMG_PATH = "./assets/sprites/canodown.png";
const std::string PIPEUP_IMG_PATH = "./assets/sprites/canoup.png";

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

    ALLEGRO_BITMAP *canoCima = al_load_bitmap(PIPEUP_IMG_PATH.c_str());
    if(canoCima == nullptr){
        std::cout << "Falha ao carregar canoCima" << std::endl;
        return -1;
    }

    ALLEGRO_BITMAP *canoBaixo = al_load_bitmap(PIPEDOWN_IMG_PATH.c_str());
    if(canoBaixo == nullptr){
        std::cout << "Falha ao carregar CanoBaixo" << std::endl;
        return -1;
    }

    for(int i = 0; i < NUM_CANOS; i++){
        canos[i].inicializarCanos(400, i);
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

            al_clear_to_color(al_map_rgb(0,0,0));

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
                    if(!jump){
                        velY += gravidade;
                        posY += velY;
                    } else {
                        velY = -jumpSpeed;
                        posY += velY;
                        jump = false;
                    }

                    if(posY >= 530){
                        state = inGameOver;
                    }

                    if(posY <= 0){
                        velY = 0;
                        posY = 0;
                    }
                    al_draw_bitmap(background, 0, 0, 0);
                    al_draw_bitmap(bird, posX, posY, 0);
                    al_draw_bitmap(base, 0, SCREEN_HEIGHT - 50, 0);

                    canos[0].atualizar(canos);

                    for(int i = 0; i < NUM_CANOS; i++){
                        canos[i].desenhar(canoCima, canoBaixo);
                    }

                    break;

                case inGameOver:
                    velY = 0;    
                    al_draw_filled_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(255, 0, 0));
                    al_draw_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(0,0,0), 5);
                    al_draw_text(
                        font_arial, 
                        al_map_rgb(0,0,0), 
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - FONT_SIZE, 
                        ALLEGRO_ALIGN_CENTER, 
                        "Perdeu Playboy!"
                    );
                    al_draw_text(
                        font_arial, 
                        al_map_rgb(0,0,0), 
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 + FONT_SIZE/2, 
                        ALLEGRO_ALIGN_CENTER, 
                        "Aperte ENTER p voltar ao menu"
                    );

                    al_draw_bitmap(bird, posX, posY, 0);
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
                    jump = true;
                    break;
                
                case ALLEGRO_KEY_ENTER:
                    if(state == inGameOver){
                        posY = (SCREEN_HEIGHT/2) + 10;
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
        //Eventos que acontecem quando uma tecla é soltada
        else if (event.type == ALLEGRO_EVENT_KEY_UP) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_SPACE:
                    jump = false;
                    break;
            }
        }
        //Sair quando usuario aperta o X-inho
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            endGame = true;
        }
        
        
    }

    // Destrutores dos objetos allegro
        al_destroy_display(display);
        al_destroy_event_queue(eventQueue);
        al_destroy_bitmap(background);
        al_destroy_bitmap(base);
        al_destroy_bitmap(bird);
        al_destroy_font(font_arial);
        al_destroy_timer(timer);
    
    return 0;
}