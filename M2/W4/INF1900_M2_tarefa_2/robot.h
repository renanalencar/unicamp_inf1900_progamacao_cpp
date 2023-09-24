/**
 * @file robot.h
 *
 * @brief Header da classe que representa um robô.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#pragma once
#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>
#include "item.h"
#include "map.h"
#include "treasure.h"

class Robot : public Item
{
public:
    Robot(Map *map);

    void move(char direction);

    void collect();

    void printStatus() const;

private:
    int x;
    int y;
    int energy;
    Map *map;
    Treasure treasure;
};
#endif