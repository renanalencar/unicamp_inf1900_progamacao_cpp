/**
 * @file treasure.h
 *
 * @brief Header da classe que representa um tesouro.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

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