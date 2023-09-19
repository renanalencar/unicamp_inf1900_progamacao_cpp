/**
 * @file map.h
 *
 * @brief Header da classe que representa um mapa.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#pragma once
#ifndef MAP_H
#define MAP_H

#include <vector>
#include "item.h"

class Map
{
private:
    int width;
    int height;
    std::vector<std::vector<Item *>> mapData;
    

public:
    Map(int w, int h);

    ~Map();

    void addItem(int x, int y, Item *item);

    void removeItem(int x, int y);

    void print() const;

    bool isValidPosition(int x, int y);
    
    std::vector<std::vector<Item*>> getMapData();

};

#endif