/**
 * @file jewel.cpp
 *
 * @brief Classe que representa um item do tipo joia.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include "jewel.h"

Jewel::Jewel(int jewelValue) : Item::Item("Jewel", jewelValue) {}