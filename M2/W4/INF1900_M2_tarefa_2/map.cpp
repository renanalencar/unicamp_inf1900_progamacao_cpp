/**
 * @file map.cpp
 *
 * @brief Classe que representa um mapa.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <vector>
#include "map.h"

Map::Map(int w, int h) : width(w), height(h)
{
	mapData.resize(height, std::vector<Item*>(width, nullptr));
}

Map::~Map()
{
	for (int i = 0; i < height; i++)
	{
		delete[] & mapData[i];
	}
	delete[] & mapData;
}

void Map::addItem(int x, int y, Item* item)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		mapData[y][x] = item;
	}
}

void Map::removeItem(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		mapData[y][x] = nullptr;
	}
}

void Map::print() const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (mapData[i][j] == nullptr)
			{
				std::cout << ". ";
			}
			else
			{
				std::cout << mapData[i][j]->getType()[0] << " "; //show first letter
			}
		}
		std::cout << std::endl;
	}
}

bool Map::isValidPosition(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		return true;
	}
	return false;
}

std::vector<std::vector<Item*>> Map::getMapData() 
{
	return mapData;
}