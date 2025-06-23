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
#include "button.hpp"

using namespace std;

// Define os estados que o Jogo pode Estar
enum gameState{
    inStartMenu,
    inGame,
    inGameOver,
    inScoreBoard,
    inProfileScreen
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

    if(!al_init_image_addon()){
        cout << "Falha ao iniciar pacote de imagens do Allegro" << endl;
        return -1;
    }

    if(!al_install_keyboard()){
        cout << "Falha ao iniciar teclado" << endl;
        return -1;
    }

    if(!al_install_mouse()){
        cout << "Falha ao iniciar mouse" << endl;
        return -1;
    }

    // Instancia a classe de fontes com o caminho da fonte e o tamanho
    fontesClass fonteArial(ARIAL_FONT_PATH.c_str(), ARIAL_FONT_SIZE);
    fontesClass fonteFlappy(FLAPPY_FONT_PATH.c_str(), FLAPPY_FONT_SIZE); 
    fontesClass fontePixelify(PIXELIFY_FONT_PATH.c_str(), PIXELIFY_FONT_SIZE);

    //Inicia display, fila de eventos e times
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

    // Botões do jogo
    Button B_irStartMenu(50, 120, fontePixelify.getfonte(), WHITE);
    Button B_irScoreboard(50, 120, fontePixelify.getfonte(), WHITE);
    Button B_irProfile(50, 120, fontePixelify.getfonte(), WHITE);
    Button CaixaDeTexto(40, 440, fontePixelify.getfonte(), PASTEL_WHITE);
    Button B_ChangeSkinLeft(40, 40, fonteArial.getfonte(), PASTEL_WHITE);
    Button B_ChangeSkinRight(40, 40, fonteArial.getfonte(), PASTEL_WHITE);
    
    // Seção para carregar imagens
    Imagem base(BASE_IMG_PATH);
    Imagem background(BACKGROUND_IMG_PATH);
    //Imagem titulo(TITLE_IMG_PATH);
    //Imagem gameover(GAMEOVER_IMG_PATH);

    // Instanciando Entidades
    Bird bird((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
    Scoreboard scoreboard(fontePixelify.getfonte(), fonteFlappy.getfonte());
    Canos canos[NUM_CANOS] = {Canos(SCREEN_WIDTH, 0), Canos(SCREEN_WIDTH, 1), Canos(SCREEN_WIDTH, 2), Canos(SCREEN_WIDTH, 3)};

    // Especificar de onde vem os eventos
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_mouse_event_source());

    // Variaveis do Jogo
    bool endGame = false;
    gameState state = inStartMenu;
    string playerName;
    int score = 1;

    // Inicia os timers
    al_start_timer(timer);
    double tempo_inicio = al_get_time();
    double tempo_atual = 0;
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
                    al_draw_filled_rounded_rectangle(150, 280, 650, 460, 10, 10, ORANGE);
                    al_draw_rounded_rectangle(150, 280, 650, 460, 10, 10, PASTEL_WHITE, 5);
                    B_irProfile.draw(200, 400, 0, "perfil", B_irProfile.get_cor());
                    B_irScoreboard.draw(480, 400, 0, "placar", B_irScoreboard.get_cor());
                    fonteFlappy.escrever(
                        "FLAPPY BIRD",
                        SCREEN_WIDTH/2, 200, 
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "ESPAÇO para começar",
                        SCREEN_WIDTH/2, 290, 
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "ESC para sair",
                        SCREEN_WIDTH/2, 290 + PIXELIFY_FONT_SIZE + 10, 
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "Made by grupo 4",
                        SCREEN_WIDTH/2, 560 + PIXELIFY_FONT_SIZE + 10, 
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    break;
                
                case inGame:
                    if(!bird.borda_hit(canos)){
                        bird.update_position(delta_time);
                        canos[0].atualizar(canos, NUM_CANOS, delta_time);
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
                    score++;
                    tempo_atual = current_time - tempo_inicio;
                    
                    char tempo_str[64];
                    sprintf(tempo_str, "Tempo: %.2f s", tempo_atual);
                    al_draw_text(fontePixelify.getfonte(), WHITE, 10, 10, 0, tempo_str);
                    break;
                
                case inGameOver:
                    for(int i = 0; i <NUM_CANOS; i++){
                        canos[i].desenhar();
                    }
                    bird.draw();
                    al_draw_filled_rounded_rectangle(150, 200, 650, 460, 10, 10, ORANGE);
                    al_draw_rounded_rectangle(150, 200, 650, 460, 10, 10, PASTEL_WHITE, 5);
                    B_irScoreboard.draw(480, 400, 0, "placar", B_irScoreboard.get_cor());
                    B_irStartMenu.draw(200, 400, 0, "inicio", B_irStartMenu.get_cor());
                    fontePixelify.escrever(
                        "ESPAÇO para recomeçar",
                        SCREEN_WIDTH/2, (SCREEN_HEIGHT/2 + 20),
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "pontos",
                        SCREEN_WIDTH/2, 205,
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fonteFlappy.escrever(
                        to_string(score),
                        SCREEN_WIDTH/2, 250,
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fonteFlappy.escrever(
                        "GAME OVER",
                        SCREEN_WIDTH/2, 120, 
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    break;
                
                case inScoreBoard:
                    scoreboard.drawScoreboard();
                    scoreboard.exibeInfos();
                    B_irStartMenu.draw(340, 450, 0, "inicio", B_irStartMenu.get_cor());
                    break;
                
                case inProfileScreen:
                    al_draw_filled_rounded_rectangle(150, 200, 650, 500, 10, 10, ORANGE);
                    al_draw_rounded_rectangle(150, 200, 650, 500, 10, 10, PASTEL_WHITE, 5);
                    fontePixelify.escrever(
                        "Jogando como",
                        SCREEN_WIDTH/2, 205,
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fontePixelify.escrever(
                        "skin",
                        SCREEN_WIDTH/2, 300,
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    fonteFlappy.escrever(
                        "PERFIL",
                        SCREEN_WIDTH/2, 120, 
                        WHITE, ALLEGRO_ALIGN_CENTER
                    );
                    if(playerName.empty() && !CaixaDeTexto.isActive()){
                        CaixaDeTexto.draw(180, 246, 1, "clique para editar", LIGHT_GREY);
                    } else CaixaDeTexto.draw(180, 246, 1, playerName, BLACK);
                    B_irStartMenu.draw(340, 440, 0, "inicio", B_irStartMenu.get_cor());
                    B_ChangeSkinLeft.draw(355, 380, 1, "<", LIGHT_GREY);
                    B_ChangeSkinRight.draw(405, 380, 1, ">", LIGHT_GREY);
                    bird.forced_draw(SCREEN_WIDTH/2 - 17, 340);
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
                        tempo_inicio = al_get_time(); 
                    }
                    if(state == inGameOver){
                        bird.reset_position((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
                        score = 1;
                        canos[0].reset_position(canos, NUM_CANOS);
                        tempo_inicio = al_get_time();
                        state = inGame;
                    }
                    break;
                case ALLEGRO_KEY_ENTER:
                    if(state == inProfileScreen && CaixaDeTexto.isActive()){
                        CaixaDeTexto.switchActive();
                        CaixaDeTexto.set_cor(PASTEL_WHITE);
                    }
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    if(state != inStartMenu){
                        state = inStartMenu;
                    } else {
                        endGame = true;
                    }
                    break;
            }
        }
        // Teclado do player
        else if(event.type == ALLEGRO_EVENT_KEY_CHAR){
            if(state == inProfileScreen && CaixaDeTexto.isActive()){
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
        // Mouse do Player
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            int mouse_x = event.mouse.x, mouse_y = event.mouse.y;
            switch (state)
            {
                case inStartMenu:
                    if(B_irScoreboard.isMouseHovering(mouse_x, mouse_y)){
                        if(!playerName.empty()){
                            scoreboard.updatePlayerInfo(playerName, score);
                        }
                        state = inScoreBoard;
                    }
                    else if(B_irProfile.isMouseHovering(mouse_x, mouse_y)) state = inProfileScreen;
                    break;

                case inGameOver:
                    if(B_irStartMenu.isMouseHovering(mouse_x, mouse_y)) {
                        bird.reset_position((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
                        score = 1;
                        canos[0].reset_position(canos, NUM_CANOS);
                        tempo_inicio = al_get_time();
                        state = inStartMenu;
                    }
                    else if(B_irScoreboard.isMouseHovering(mouse_x, mouse_y)){
                        bird.reset_position((float)SCREEN_WIDTH/4, (float)SCREEN_HEIGHT/2);
                        score = 1;
                        canos[0].reset_position(canos, NUM_CANOS);
                        tempo_inicio = al_get_time();
                        state = inScoreBoard;
                    }
                    break;

                case inScoreBoard:
                    if(B_irStartMenu.isMouseHovering(mouse_x, mouse_y)) state = inStartMenu;
                    break;

                case inProfileScreen:
                    if(B_irStartMenu.isMouseHovering(mouse_x, mouse_y)) state = inStartMenu;
                    else if(CaixaDeTexto.isMouseHovering(mouse_x, mouse_y)) {
                        CaixaDeTexto.switchActive();
                        if(CaixaDeTexto.isActive()) CaixaDeTexto.set_cor(WHITE);
                        else CaixaDeTexto.set_cor(PASTEL_WHITE);
                    }
                    else if(B_ChangeSkinLeft.isMouseHovering(mouse_x, mouse_y)) {
                        if(bird.getCor() == Red) bird.setCor(Yellow);
                        else if(bird.getCor() == Blue) bird.setCor(Red);
                    }
                    else if(B_ChangeSkinRight.isMouseHovering(mouse_x, mouse_y)) {
                        if(bird.getCor() == Red) bird.setCor(Blue);
                        else if(bird.getCor() == Yellow) bird.setCor(Red);
                    }
                    break;

                case inGame:
                    break;
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