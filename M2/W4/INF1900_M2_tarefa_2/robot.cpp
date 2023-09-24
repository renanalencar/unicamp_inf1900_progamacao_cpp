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

Robot::Robot(Map* map) : Item("Robot", 0), map(map), energy(10)
{
	// Inicialize a posição inicial do robô (aqui assumindo 0,0)
	x = 0;
	y = 0;
	map->addItem(x, y, this);
}

void Robot::move(char direction)
{
	if (energy == 0) 
	{
		return;
	}

	switch (direction)
	{
	case 'w':
		if (map->isValidPosition(x, y - 1))
		{
			map->removeItem(x, y);
			y--;
			map->addItem(x, y, this);
			energy--;
		}
		break;
	case 'a':
		if (map->isValidPosition(x - 1, y))
		{
			map->removeItem(x, y);
			x--;
			map->addItem(x, y, this);
			energy--;
		}
		break;
	case 's':
		if (map->isValidPosition(x, y + 1))
		{
			map->removeItem(x, y);
			y++;
			map->addItem(x, y, this);
			energy--;
		}
		break;
	case 'd':
		if (map->isValidPosition(x + 1, y))
		{
			map->removeItem(x, y);
			x++;
			map->addItem(x, y, this);
			energy--;
		}
		break;

	default:
		break;
	}
}

void Robot::collect()
{
	//right
	if (map->isValidPosition(x + 1, y) && map->getMapData()[y][x + 1] != nullptr)
	{
		Item item = *map->getMapData()[y][x + 1];
		map->removeItem(x + 1, y);
		treasure.add(&item);
	}
	//left
	if (map->isValidPosition(x - 1, y) && map->getMapData()[y][x - 1] != nullptr)
	{
		Item item = *map->getMapData()[y][x - 1];
		map->removeItem(x - 1, y);
		treasure.add(&item);
	}
	//Upper
	if (map->isValidPosition(x, y - 1) && map->getMapData()[y - 1][x] != nullptr)
	{
		Item item = *map->getMapData()[y - 1][x];
		map->removeItem(x, y - 1);
		treasure.add(&item);
	}
	//bottom
	if (map->isValidPosition(x, y + 1) && map->getMapData()[y + 1][x] != nullptr)
	{
		Item item = *map->getMapData()[y + 1][x];
		map->removeItem(x, y + 1);
		treasure.add(&item);
	}
	// Upper Diagonal left
	if (map->isValidPosition(x - 1, y - 1) && map->getMapData()[y - 1][x - 1] != nullptr)
	{
		Item item = *map->getMapData()[y - 1][x - 1];
		map->removeItem(x - 1, y - 1);
		treasure.add(&item);
	}
	// Upper Diagonal right
	if (map->isValidPosition(x + 1, y - 1) && map->getMapData()[y - 1][x + 1] != nullptr)
	{
		Item item = *map->getMapData()[y - 1][x + 1];
		map->removeItem(x + 1, y - 1);
		treasure.add(&item);
	}
	// bottom Diagonal left
	if (map->isValidPosition(x - 1, y - 1) && map->getMapData()[y + 1][x - 1] != nullptr)
	{
		Item item = *map->getMapData()[y + 1][x - 1];
		map->removeItem(x - 1, y + 1);
		treasure.add(&item);
	}
	// bottom Diagonal right
	if (map->isValidPosition(x + 1, y + 1) && map->getMapData()[y + 1][x + 1] != nullptr)
	{
		Item item = *map->getMapData()[y + 1][x + 1];
		map->removeItem(x + 1, y + 1);
		treasure.add(&item);
	}
}

void Robot::printStatus() const
{
	std::cout << "Energy: " << energy << std::endl;
	std::cout << "Score: " << treasure.getValue() << std::endl;
	if (energy == 0) {
		std::cout << "No Energy left:" << std::endl;
	}
}