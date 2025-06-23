#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fontesClass.hpp"
#include "db.hpp"

using namespace std;

class Scoreboard{
    
    int num_players;
    ALLEGRO_FONT *fonte;
    ALLEGRO_FONT *fonteCabecalho;
    DB database;

    public:

    Scoreboard(ALLEGRO_FONT *fonte, ALLEGRO_FONT *fonteCabecalho);

    void drawScoreboard();

    void exibeInfos();

    void updatePlayerInfo(string player, int score);

    private:
    void updateNumPlayers();
};

#endif