#include "scoreboard.hpp"
#include "constants.hpp"

Scoreboard::Scoreboard(ALLEGRO_FONT *fonte) :
    fonte(fonte),
    num_players(0),
    database(DB_PATH)
{
    
}

bool Scoreboard::isDbEmpty()
{
    
}
bool Scoreboard::PlayerExists(string player){
    
}
void Scoreboard::updateNumPlayers(){
    
}
void Scoreboard::drawScoreboard()
{
    al_draw_filled_rounded_rectangle(100, 100, 700, 500, 10, 10, al_map_rgb(255, 165, 0));
    al_draw_rounded_rectangle(100, 100, 700, 500, 10, 10, al_map_rgb(253,253,253), 5);
    al_draw_filled_rounded_rectangle(130, 200, 670, 400, 10, 10, al_map_rgb(253,253,253));
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
    
}

void Scoreboard::addPlayerInfo(string player){
    
}