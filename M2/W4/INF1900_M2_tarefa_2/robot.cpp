/**
 * @file robot.cpp
 *
 * @brief Classe que representa um robô.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include "robot.h"

Robot::Robot(Map *map) : Item("Robot", 0), map(map), energy(10)
{
    // Inicialize a posição inicial do robô (aqui assumindo 0,0)
    x = 0;
    y = 0;
}

void Robot::move(char direction)
{
    // Implemente o movimento do robô com tratamento de erros
}

void Robot::collect()
{
    // Implemente a lógica de coleta de itens
}

void Robot::printStatus() const
{
    std::cout << "Energy: " << energy << std::endl;
    std::cout << "Score: " << treasure.getValue() << std::endl;
}