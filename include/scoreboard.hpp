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
    vector <string> linhas;
    ALLEGRO_FONT *fonte;
    DB database;

    public:

    Scoreboard(ALLEGRO_FONT *fonte);

    bool isDbEmpty();

    void drawScoreboard();

    void exibeInfos();

    void addPlayerInfo(string player);

    bool PlayerExists(string player);

    void updateNumPlayers();
};

#endif