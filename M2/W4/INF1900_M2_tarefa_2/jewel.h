/**
 * @file jewel.h
 *
 * @brief Header da classe que representa um item do tipo joia.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

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