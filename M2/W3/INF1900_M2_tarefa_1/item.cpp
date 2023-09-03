/**
 * @file item.cpp
 *
 * @brief Classe que representa um item.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include "item.h"

Item::Item(std::string const &itemType, int itemValue) : type(itemType), value(itemValue) {}

std::string Item::getType() const
{
    return type;
}

int Item::getValue() const
{
    return value;
}
