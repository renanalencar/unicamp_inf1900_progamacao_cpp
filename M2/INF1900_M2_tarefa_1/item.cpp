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
