#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Scoreboard{
    
    int num_players;
    vector <string> player_names;
    bool isDbEmpty();

    public:
    Scoreboard();

    void drawScoreboard();

    void exibeInfos();

    void updatePlayerInfo();

    bool PlayerExists();
};

#endif