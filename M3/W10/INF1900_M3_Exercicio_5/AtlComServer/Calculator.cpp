#include "pch.h"
#include "Calculator.h"
#include <time.h>


// Essa implementação utiliza o método de Monte Carlo para aproximar π.
STDMETHODIMP CCalculator::ApproximatePi(DOUBLE* result)
{
    if (!result)
        return E_POINTER;

    // Defina o número total de pontos
    const int totalPoints = 1000000;

    // Inicialize o gerador de números aleatórios
    srand(static_cast<unsigned int>(time(nullptr)));

    // Inicialize o contador de pontos dentro do círculo
    int pointsInsideCircle = 0;

    // Gere pontos aleatórios e conte quantos estão dentro do círculo
    for (int i = 0; i < totalPoints; ++i)
    {
        double x = (double)rand() / RAND_MAX * 2.0 - 1.0; // Números entre -1 e 1
        double y = (double)rand() / RAND_MAX * 2.0 - 1.0;

        if (x * x + y * y <= 1.0)
            pointsInsideCircle++;
    }

    // Calcule a aproximação de π
    *result = 4.0 * (static_cast<double>(pointsInsideCircle) / totalPoints);

    return S_OK;
}