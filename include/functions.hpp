///@file functions.hpp

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

bool compararHighScore(const std::pair<std::string, int>& a,
    const std::pair<std::string, int>& b) {
    return a.second > b.second;
}

#endif