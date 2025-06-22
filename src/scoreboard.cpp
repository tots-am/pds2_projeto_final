#include "scoreboard.hpp"
#include "constants.hpp"

const int NUM_LETRAS = 32;

Scoreboard::Scoreboard(ALLEGRO_FONT *fonte) :
    num_players(0),
    fonte(fonte),
    database(DB_PATH)
{}
void Scoreboard::updateNumPlayers(){
    std::vector<std::pair<std::string, int>> registros = database.lerTodos();
    this->num_players = registros.size(); 
    //std::cout << this->num_players << std::endl;;
}
void Scoreboard::drawScoreboard()
{
    al_draw_filled_rounded_rectangle(100, 100, 700, 500, 10, 10, al_map_rgb(255, 165, 0));
    al_draw_rounded_rectangle(100, 100, 700, 500, 10, 10, al_map_rgb(253,253,253), 5);
    al_draw_filled_rounded_rectangle(130, 180, 670, 440, 10, 10, al_map_rgb(253,253,253));
    al_draw_text(
        fonte,
        al_map_rgb(0,0,0),
        SCREEN_WIDTH/2, 
        185,
        ALLEGRO_ALIGN_CENTER,
        "Jogador ------------ High Score"
    );
    al_draw_text(
        fonte,
        al_map_rgb(255,255,255),
        SCREEN_WIDTH/2, 
        450,
        ALLEGRO_ALIGN_CENTER,
        "Aperte ESC para voltar ao menu"
    );
}
void Scoreboard::exibeInfos(){
    int offset = 0;
    std::vector <std::pair<std::string, int>> registros = database.lerTodos();
    int i = 0;
    while(i < num_players){
        if(i == num_players){ break; }
        else if(i == 5){ break; }
        std::string nome = registros[i].first;
        std::string high_score = std::to_string(registros[i].second);
        int dif = NUM_LETRAS - nome.size() - high_score.size();
        std::string space;
        for(int j = 0; j < dif; j++){
            space.push_back('-');
        }
        std::string joined = nome + " " + space + " " + high_score;
        al_draw_text(
            fonte,
            al_map_rgb(0,0,0),
            SCREEN_WIDTH/2,
            232 + offset,
            ALLEGRO_ALIGN_CENTER,
            joined.c_str()
        );
        offset += 40;
        i++;
    }
}

void Scoreboard::updatePlayerInfo(string player, int score){
    int currentScore = database.buscarHighScore(player);
    if(currentScore == -1){
        database.adicionar(player, score);
    }
    else if(score > currentScore){
        database.atualizar(player, score);
    }
    this->updateNumPlayers();
}