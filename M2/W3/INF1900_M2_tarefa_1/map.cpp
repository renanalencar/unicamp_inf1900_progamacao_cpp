/**
 * @file map.cpp
 *
 * @brief Classe que representa um mapa.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <vector>
#include "map.h"

Map::Map(int w, int h) : width(w), height(h) {
    mapData.resize(height, std::vector<char>(width, ' '));
}

void Map::addItem(int x, int y, char item) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        mapData[y][x] = item;
    }
}

void Map::removeItem(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        mapData[y][x] = ' ';
    }
}

void Map::print() const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << mapData[y][x] << ' ';
        }
        std::cout << std::endl;
    }
}