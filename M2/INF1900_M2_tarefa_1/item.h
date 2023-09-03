#pragma once
#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
    std::string type;
    int value;

public:
    Item(std::string const &itemType, int itemValue);
    std::string getType() const;
    int getValue() const;
};

#endif