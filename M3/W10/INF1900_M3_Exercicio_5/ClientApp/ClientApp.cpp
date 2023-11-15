/**
 * @file ClientApp.cpp
 *
 * @brief Classe Client com função main para execução dos pontos da atividade.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

// ClientApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <objbase.h>
#include "\Unicamp\M3\W10\INF1900_M3_Exercicio_5\ATLProject\ATLProject_i.c"
#include "\Unicamp\M3\W10\INF1900_M3_Exercicio_5\ATLProject\ATLProject_i.h"

int main()
{
	CoInitializeEx(nullptr, COINIT::COINIT_MULTITHREADED);
	ICalculator* pCalculator;
	HRESULT hr = CoCreateInstance(CLSID_Calculator, nullptr, CLSCTX_INPROC_SERVER, IID_ICalculator, (LPVOID*)&pCalculator);

	if(SUCCEEDED(hr)) 
	{
		pCalculator->AddRef();
		double piApproximation;
		pCalculator->ApproximatePi(&piApproximation);
		
		std::cout << "Aproximate PI: " << piApproximation;
	}

	CoUninitialize();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
