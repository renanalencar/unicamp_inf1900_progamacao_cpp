/**
 * @file food.h
 *
 * @brief Header da classe que representa um item do tipo comida.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "item.h"

class Food : public Item
{
public:
    explicit Food(int foodValue);
};

#endif