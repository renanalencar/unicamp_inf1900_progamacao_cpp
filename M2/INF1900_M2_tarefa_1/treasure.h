#pragma once
#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include "jewel.h"
#include "food.h"

class Treasure
{
private:
    std::vector<Item *> items;

public:
    int getValue() const;

    void add(Jewel *jewel);

    void add(Food *food);

    void remove(Item *item);
};

#endif