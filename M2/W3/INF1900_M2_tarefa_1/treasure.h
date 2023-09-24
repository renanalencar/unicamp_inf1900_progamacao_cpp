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

#include <vector>
#include "item.h"
#include "jewel.h"
#include "food.h"

class Treasure : public Item
{
private:
    std::vector<Item *> items;

public:
    explicit Treasure();

    int getValue() const;

    void add(Jewel *jewel);

    void add(Food *food);

    void remove(Item *item);
};

#endif