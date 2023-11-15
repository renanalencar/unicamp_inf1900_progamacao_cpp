/**
 * @file ex2.cpp
 *
 * @brief Classe Calculator com função AproximatePi.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

// Calculator.cpp : Implementation of CCalculator

#include "pch.h"
#include "Calculator.h" 
#include <random>

STDMETHODIMP CCalculator::ApproximatePi(double* result)
{ 
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    int totalPoints = 1000000;
    int insideCircle = 0;

    for (int i = 0; i < totalPoints; ++i)
    {
        double x = distribution(generator);
        double y = distribution(generator);

        if (x * x + y * y <= 1.0)
        {
            ++insideCircle;
        }
    }

    *result = 4.0 * static_cast<double>(insideCircle) / static_cast<double>(totalPoints);

    return S_OK;
}