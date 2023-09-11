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

class Map
{
private:
    int width;
    int height;
    std::vector<std::vector<char>> mapData;

public:
    Map(int w, int h);

    void addItem(int x, int y, char item);

    void removeItem(int x, int y);

    void print() const;
};

#endif