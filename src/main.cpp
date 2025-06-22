#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <array>
#include "birdClass.hpp"
#include "canos.hpp"
#include "fontesClass.hpp"
#include "constants.hpp"
#include "Imagem.hpp"
#include "scoreboard.hpp"

using namespace std;

// Define os estados que o Jogo pode Estar
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

    //Inicializações das Funções da Biblioteca do Allegro
    if (!al_init()) {
        cout << "Falha ao iniciar allegro" << endl;
        return -1;
    }

    if(!al_init_font_addon()){
        cout << "Falha ao iniciar pacote de fontes Allegro" << endl;
        return -1;
    }

    if(!al_init_ttf_addon()){
        cout << "Falha ao iniciar pacote de fontes ttf Allegro" << endl;
        return -1;
    }

    if(!al_init_primitives_addon()){
        cout << "Falha ao iniciar pacote de primitivas" << endl;
        return -1;
    }

    // Instancia a classe de fontes com o caminho da fonte e o tamanho
    fontesClass fonteArial(ARIAL_FONT_PATH.c_str(), ARIAL_FONT_SIZE);
    fontesClass fonteFlappy(FLAPPY_FONT_PATH.c_str(), FLAPPY_FONT_SIZE); 
    fontesClass fontePixelify(PIXELIFY_FONT_PATH.c_str(), PIXELIFY_FONT_SIZE);

    if(fonteArial.getfonte() == nullptr){
        cout << "Falha ao iniciar fonte" << endl;
        return -1;
    }
    if(fonteFlappy.getfonte() == nullptr){
        cout << "Falha ao iniciar fonte Flappy" << endl;
        return -1;
    }

    if(!al_init_image_addon()){
        cout << "Falha ao iniciar pacote de imagens do Allegro" << endl;
        return -1;
    }

    if(!al_install_keyboard()){
        cout << "Falha ao iniciar teclado" << endl;
        return -1;
    }

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if(!display){
        cout << "Falha ao criar display" << endl;
        return -1;
    }

    eventQueue= al_create_event_queue();
    if (!eventQueue) {
        cout << "Falha ao iniciar fila de eventos" << endl;
        al_destroy_display(display);
        return -1;
    }

    timer = al_create_timer(1.0/FPS);
    if(!timer){
        cout << "Falha ao Iniciar Timer" << endl;
        al_destroy_display(display);
        al_destroy_event_queue(eventQueue);
        return -1;
    }
    
    // Seção para carregar imagens
    Imagem base(BASE_IMG_PATH);
    Imagem background(BACKGROUND_IMG_PATH);
    //Imagem titulo(TITLE_IMG_PATH);
    Imagem gameover(GAMEOVER_IMG_PATH);

    // Instanciando Entidades
    Bird bird((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
    Scoreboard scoreboard(fonteArial.getfonte());
    Canos canos[NUM_CANOS] = {Canos(SCREEN_WIDTH, 0), Canos(SCREEN_WIDTH, 1), Canos(SCREEN_WIDTH, 2), Canos(SCREEN_WIDTH, 3)};

    // Especificar de onde vem os eventos
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());

    // Variaveis do Jogo
    bool endGame = false;
    gameState state = inStartMenu;
    string playerName;
    int score = 1;

    // Inicia o timer
    al_start_timer(timer);

    double last_time = al_get_time();

    //al_rest(3.0);

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
            background.exibir(0, 0);

            // Desenha a base
            base.exibir(0, 550);

            // Switch para escolher em qual tela do jogo o Usuario está e fazer as atualizações
            switch (state)
            {
                case inStartMenu:    
                    //titulo.exibir((float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/3);
                    al_draw_filled_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(255, 165, 0));
                    al_draw_rounded_rectangle(150, 200, 650, 400, 10, 10, al_map_rgb(253,253,150), 5);
                    al_draw_filled_rounded_rectangle(180, 280, 620, 320, 10, 10, al_map_rgb(255,255,255));
                    fonteFlappy.escrever(
                        "FLAPPY BIRD",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - 8 *FLAPPY_FONT_SIZE/2, 
                        al_map_rgb(163, 244, 80), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "Digite seu nome:",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - 4* PIXELIFY_FONT_SIZE/2, 
                        al_map_rgb(255,255,255), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "Aperte ESPAÇO para começar",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 + 2* PIXELIFY_FONT_SIZE/2, 
                        al_map_rgb(255,255,255), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        playerName,
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - ARIAL_FONT_SIZE/2, 
                        al_map_rgb(0,0,0), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    break;
                
                case inGame:
                    if(!bird.borda_hit()){
                        bird.update_position(delta_time);
                        canos[0].atualizar(canos, NUM_CANOS);
                        score++;
                    } else {
                        if(!playerName.empty()){
                            scoreboard.updatePlayerInfo(playerName, score);
                        }
                        state = inGameOver;
                    }

                    bird.draw();
                    for(int i = 0; i <NUM_CANOS; i++){
                        canos[i].desenhar();
                    }
                    break;
                
                case inGameOver:
                    for(int i = 0; i <NUM_CANOS; i++){
                        canos[i].desenhar();
                    }
                    al_draw_filled_rounded_rectangle(150, 200, 650, 450, 10, 10, al_map_rgb(255, 165, 0));
                    al_draw_rounded_rectangle(150, 200, 650, 450, 10, 10, al_map_rgb(253,253,253), 5);
                    fonteFlappy.escrever(
                        "ESPAÇO para recomeçar",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 - 8 *FLAPPY_FONT_SIZE/2,  
                        al_map_rgb(163, 244, 80), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "ESPAÇO para recomeçar",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 -  4* PIXELIFY_FONT_SIZE/2,
                        al_map_rgb(255,255,255), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "Aperte ENTER para ver placar",
                        SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2 + PIXELIFY_FONT_SIZE/2, 
                        al_map_rgb(255,255,255), 
                        ALLEGRO_ALIGN_CENTER
                    );
                    gameover.exibir((float)(SCREEN_WIDTH-gameover.largura)/2, 210);
                    bird.draw();
                    break;
                
                case inScoreBoard:
                    scoreboard.drawScoreboard();
                    scoreboard.exibeInfos();
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
                    else if(state == inStartMenu){
                        state = inGame;
                    }
                    if(state == inGameOver){
                        bird.reset_position((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
                        state = inGame;
                    }
                    break;
                
                case ALLEGRO_KEY_ENTER:
                    if(state == inGameOver){
                        bird.reset_position((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
                        state = inScoreBoard;
                    }
                    else if(state == inStartMenu){
                        if(!playerName.empty()){
                            scoreboard.updatePlayerInfo(playerName, score);
                        }
                        state = inScoreBoard;
                    }
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    if(state == inScoreBoard || state == inGame || state == inGameOver ){
                        bird.reset_position((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
                        state = inStartMenu;
                    } else {
                        endGame = true;
                    }
                    break;
            }
        }
        else if(event.type == ALLEGRO_EVENT_KEY_CHAR){
            if(state == inStartMenu){
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_BACKSPACE:
                        if(!playerName.empty()){
                            playerName.pop_back();
                        }
                        break;
                    case ALLEGRO_KEY_SPACE:
                        break;
                    case ALLEGRO_KEY_ESCAPE:
                        break;
                    default :
                        if(playerName.size() < MAX_NAME_SIZE){
                            if (event.keyboard.unichar >= 32) {
                                playerName.push_back((char)event.keyboard.unichar);
                            }
                        }
                        break;
                }
            }
        }
        //Sair quando usuario aperta o X-inho
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            endGame = true;
        }
    }

    if(timer) al_destroy_timer(timer);
    if(eventQueue) al_destroy_event_queue(eventQueue);
    if(display) al_destroy_display(display);

    return 0;
}