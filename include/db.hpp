#ifndef DB_HPP
#define DB_HPP

#include <string>
#include <vector>
#include <utility> // para std::pair

class DB {
public:
    DB(const std::string& path = "./db/db.txt");

    // Create
    void adicionar(const std::string& nome, int high_score);

    // Read
    std::vector<std::pair<std::string, int>> lerTodos() const;
    int buscarHighScore(const std::string& nome) const;

    // Update
    void atualizar(const std::string& nome, int novo_high_score);

    // Delete
    bool remover(const std::string& nome);

private:
    std::string path;

    // Função auxiliar para salvar todos os registros novamente no arquivo
    void salvarTodos(const std::vector<std::pair<std::string, int>>& registros) const;
};

#endif
