/**
 * @file treasure.cpp
 *
 * @brief Classe que representa um tesouro.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <vector>
#include "treasure.h"

Treasure::Treasure() : Item::Item("treasure", 0) {}

int Treasure::getValue() const
{
    int totalValue = 0;
    for (Item const *item : items)
    {
        totalValue += item->getValue();
    }
    return totalValue;
}

void Treasure::add(Jewel *jewel)
{
    items.push_back(jewel);
}

void Treasure::add(Food *food)
{
    items.push_back(food);
}

void Treasure::remove(Item *item)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (*it == item)
        {
            items.erase(it);
            delete item;
            break;
        }
    }
}