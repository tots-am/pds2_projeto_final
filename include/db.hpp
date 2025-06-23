///@file db.hpp

#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <vector>
#include <utility>
#include <constants.hpp>

/**
 * @class DB
 * @brief Representa o arquivo de texto usado para salvar as informações dos jogadores no fomato key value
 * 
 * A classe é responsável por realizar as operações de CRUD no arquivo de texto, e interagir com a classe ScoreBoard
 * Cada linha no arquivo representa um player
 */
class DB {
    public:
        /**
         * @brief Construtor Principal que instancia a classe DB com caminho pre-definido
         * 
         * @param path Caminho para o arquivo Database @see constants.hpp
         */
        DB(const std::string& path = DB_PATH);

        /**
         * @brief Usada para adicionar uma nova linha no arquivo de texto, ou seja, um novo player
         * @param nome Nome do Player
         * @param high_score O maior score desse player ate o momento
         */
        void adicionar(const std::string& nome, int high_score);

        /**
         * @brief Usada para ler todas as informações do arquivo
         * @return Um vetor ordenado com os players
         * @note Retorna o vetor ordenado, usando redefinição do operador > @see functions.hpp
         */
        std::vector<std::pair<std::string, int>> lerTodos() const;
        /**
         * @brief Usada para buscar um jogador no arquivo
         * @param nome O nome do jogador que se quer buscar
         * @return -1, caso o jogador não está no arquivo
         * @return maior pontuação, caso o jogador tenha o nome no arquivo
         */
        int buscarHighScore(const std::string& nome) const;

        /**
         * @brief Usada para atualizar as informações de um jogador que já está presente no banco
         * @param nome Nome do jogador
         * @param novo_high_score Nova maior pontuação do Jogador
         */
        void atualizar(const std::string& nome, int novo_high_score);

        /**
         * @brief Usada para deletar as informações de um jogador do arquivo
         * @param nome O nome do jogador que será removido
         */
        bool remover(const std::string& nome);

    private:
        std::string path;

        /** 
         * @brief Função auxiliar para salvar todos os registros novamente no arquivo
         * @param registros O vetor que representa todos os players
        */
        void salvarTodos(const std::vector<std::pair<std::string, int>>& registros) const;
};

#endif
