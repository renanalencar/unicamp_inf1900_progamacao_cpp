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