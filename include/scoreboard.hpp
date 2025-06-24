///@file scoreboard.hpp

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

/**
 * @class ScoreBoard 
 * @brief Representa a Tela de Placar do jogo
 * 
 * A classe é responsável por interagir com o arquivo de texto que guarda as informações dos jogadores,
 * por desenhar o placar, atualizando e exibindo suas informações.
 */
class Scoreboard{
    
    int num_players;
    ALLEGRO_FONT *fonte;
    ALLEGRO_FONT *fonteCabecalho;
    DB database;

    public:

    /**
     * @brief Construtor principal que cria o ScoreBoard com uma fonte do texto e do cabeçalho pré definidas
     * 
     * @param fonte A fonte que será usada para exibir informações do placar
     * @param fonteCabecalho A fonte que será usada no cabeçalho da tela (escrito "placar")
     * @note Inicia numero de players de acordo com a database existente
     * @note Inicia DB com um path pré-definido @see constants.hpp
     */
    Scoreboard(ALLEGRO_FONT *fonte, ALLEGRO_FONT *fonteCabecalho, string db_path);

    /**
     * @brief Desenha o Placar na tela, mas sem renderizar as informações dos jogadores
     */
    void drawScoreboard();
    /**
     * @brief Escreve na tela as informações dos jogadores, em ordem do maior score para o menor.
     * @note Exibe apenas o top 5, devido as limitações de espaço
     */
    void exibeInfos();

    /**
     * @brief Atualiza informações de um jogador específico, caso ele tenha batido seu High Score
     * @param player String que guarda o nome do jogador
     * @param score A pontuação que o jogador teve após o final da rodada
     * @note Deve ser chamado sempre que o Jogador morrer
     */
    void updatePlayerInfo(string player, int score);

    private:
    /**
     * @brief Método auxiliar usado para atualizar o numero de jogadores.
     */
    void updateNumPlayers();
};

#endif