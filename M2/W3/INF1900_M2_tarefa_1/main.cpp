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

int main()
{
    Map gameMap(10, 10);
    Treasure treasure;

    // Adicione algumas joias e comida ao ambiente
    Jewel jewel(50);
    Food food(20);

    treasure.add(&jewel);
    treasure.add(&food);

    gameMap.addItem(2, 3, &jewel);    // Exemplo de posição de joia
    gameMap.addItem(7, 5, &food);     // Exemplo de posição de comida
    gameMap.addItem(4, 6, &treasure); // Posição do baú

    std::string userInput;

    while (true)
    {
        std::cout << "Digite 'exit' para sair ou 'map' para exibir o mapa: ";
        std::cin >> userInput;

        if (userInput == "exit")
        {
            break;
        }
        else if (userInput == "map")
        {
            gameMap.print();
            std::cout << "Total de joias no baú: " << treasure.getValue() << std::endl;
        }
        else
        {
            std::cout << "Comando inválido. Tente novamente." << std::endl;
        }
    }

    return 0;
}
