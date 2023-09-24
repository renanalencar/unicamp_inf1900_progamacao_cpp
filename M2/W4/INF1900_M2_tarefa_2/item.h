/**
 * @file item.h
 *
 * @brief Header da classe que representa um item.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

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