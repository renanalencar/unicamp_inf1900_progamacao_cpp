/**
 * @file main.cpp
 *
 * @brief Programa que simula um ambiente com um mapa e um baú de tesouro.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <vector>
#include "map.h"
#include "jewel.h"
#include "food.h"
#include "treasure.h"
#include "robot.h"

int main()
{
    // Crie um mapa 30x30
    Map gameMap(30, 30);
    Treasure treasure;

    // Povoe o mapa com joias, comidas e tesouro em posições aleatórias
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 30;
        int y = rand() % 30;
        gameMap.addItem(x, y, new Jewel(rand() % 10));
    }

    for (int i = 0; i < 5; i++)
    {
        int x = rand() % 30;
        int y = rand() % 30;
        gameMap.addItem(x, y, new Food(rand() % 5));
    }

    // Adicione algumas joias e comida para o baú de tesouro
    Jewel jewel(50);
    Food food(20);

    int treasureX = rand() % 30;
    int treasureY = rand() % 30;
    Treasure treasure;

    treasure.add(&jewel);
    treasure.add(&food);

    gameMap.addItem(treasureX, treasureY, &treasure);

    // Crie o robô no mapa
    Robot robot(&gameMap);

    char command;
    while (true)
    {
        // Limpe a tela (apenas para sistemas Unix-like)
        system("clear");

        // Imprima o mapa
        gameMap.print();

        // Imprima o status do robô
        robot.printStatus();

        // Leia o comando do usuário
        std::cout << "Digite um comando (w, a, s, d, g, ou exit): ";
        std::cin >> command;

        if (command == 'exit')
        {
            break;
        }

        // Execute o comando do usuário
        switch (command)
        {
        case 'w':
        case 'a':
        case 's':
        case 'd':
            robot.move(command);
            break;
        case 'g':
            robot.collect();
            break;
        default:
            std::cout << "Comando inválido!" << std::endl;
        }
    }

    return 0;
}
