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