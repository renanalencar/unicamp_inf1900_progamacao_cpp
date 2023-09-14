/**
 * @file food.cpp
 *
 * @brief Classe que representa um item do tipo comida.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include "food.h"

Food::Food(int foodValue) : Item::Item("Food", foodValue) {}