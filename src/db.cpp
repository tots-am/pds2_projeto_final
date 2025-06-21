#include "db.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

DB::DB(const std::string& path) : path(path) {}

// Create
void DB::adicionar(const std::string& nome, int high_score) {
    std::ofstream arquivo(path, std::ios::app);
    if (arquivo.is_open()) {
        arquivo << nome << " " << high_score << std::endl;
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
    }
}

// Read
std::vector<std::pair<std::string, int>> DB::lerTodos() const {
    std::vector<std::pair<std::string, int>> registros;
    std::ifstream arquivo(path);
    std::string nome;
    int score;

    if (arquivo.is_open()) {
        while (arquivo >> nome >> score) {
            registros.emplace_back(nome, score);
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
    }

    return registros;
}

int DB::buscarHighScore(const std::string& nome) const {
    std::ifstream arquivo(path);
    std::string nomeArquivo;
    int score;

    if (arquivo.is_open()) {
        while (arquivo >> nomeArquivo >> score) {
            if (nomeArquivo == nome) {
                arquivo.close();
                return score;
            }
        }
        arquivo.close();
    }

    return -1; // Indica que o nome não foi encontrado
}

// Update
bool DB::atualizar(const std::string& nome, int novo_high_score) {
    auto registros = lerTodos();
    bool atualizado = false;

    for (auto& par : registros) {
        if (par.first == nome) {
            par.second = novo_high_score;
            atualizado = true;
            break;
        }
    }

    if (atualizado) {
        salvarTodos(registros);
    }

    return atualizado;
}

// Delete
bool DB::remover(const std::string& nome) {
    auto registros = lerTodos();
    auto it = std::remove_if(
        registros.begin(),
        registros.end(),
        [&nome](const std::pair<std::string, int>& par) {
        return par.first == nome;
    });

    if (it != registros.end()) {
        registros.erase(it, registros.end());
        salvarTodos(registros);
        return true;
    }

    return false;
}

// Função auxiliar para sobrescrever o arquivo
void DB::salvarTodos(const std::vector<std::pair<std::string, int>>& registros) const {
    std::ofstream arquivo(path, std::ios::trunc);
    if (arquivo.is_open()) {
        for (const auto& par : registros) {
            arquivo << par.first << " " << par.second << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para sobrescrita." << std::endl;
    }
}
