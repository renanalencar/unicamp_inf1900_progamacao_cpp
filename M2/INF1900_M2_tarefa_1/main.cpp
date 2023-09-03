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
    Jewel jewel1(50);
    Jewel jewel2(30);
    Food food1(20);

    treasure.add(&jewel1);
    treasure.add(&jewel2);
    treasure.add(&food1);

    gameMap.addItem(2, 3, 'J'); // Exemplo de posição de joia
    gameMap.addItem(7, 5, 'J'); // Exemplo de posição de joia
    gameMap.addItem(4, 6, 'T'); // Posição do baú

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
