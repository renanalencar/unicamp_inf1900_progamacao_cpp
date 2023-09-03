#pragma once
#ifndef JEWEL_H
#define JEWEL_H

#include "item.h"

class Jewel : public Item
{
public:
    explicit Jewel(int jewelValue);
};

#endif