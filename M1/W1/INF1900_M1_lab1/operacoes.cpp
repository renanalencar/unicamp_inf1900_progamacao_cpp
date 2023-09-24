/**
 * @file operacoes.cpp
 *
 * @brief Calculadora simples em C++
 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include<iostream>

int main()
{
    std::cout << "          _   _       _     _           _        __ "<< std::endl;
    std::cout << "     /\\  | | (_)     (_)   | |         | |      /_ |"<< std::endl;
    std::cout << "    /  \\ | |_ ___   ___  __| | __ _  __| | ___   | |"<< std::endl;
    std::cout << "   / /\\ \\| __| \\ \\ / / |/ _` |/ _` |/ _` |/ _ \\  | |"<< std::endl;
    std::cout << "  / ____ \\ |_| |\\ V /| | (_| | (_| | (_| |  __/  | |"<< std::endl;
    std::cout << " /_/    \\_\\__|_| \\_/ |_|\\__,_|\\__,_|\\__,_|\\___|  |_|"<< std::endl;

    std::cout << "\n Enter the first number:"<< std::endl;                 
    int numero1;
    std::cin >> numero1;
    std::cout << "\n Enter the second number:"<< std::endl;                 
    int numero2;
    std::cin >> numero2;
     
    std::cout << "\n Escolha uma opção abaixo:"<< std::endl;                 
    std::cout << "\n 1- Sum \n 2- Subtraction  \n 3- Division \n 4- Multiplication \n 5- AND \n 6- OR \n 7- XOR \n 8- AND Bitwise"<< std::endl;                 
    int opcao;
    std::cin >> opcao;
    
    int resultado;
    switch (opcao)
    {
        case 1:
             std::cout <<  numero1 << " + " << numero2 << " = " << numero1+numero2 << std::endl;   
            break;
        case 2:
            std::cout <<  numero1 << " - " << numero2 << " = " << numero1-numero2 << std::endl;   
            break;
        case 3:
            std::cout <<  numero1 << " / " << numero2 << " = " << numero1/numero2 << std::endl;   
            break;
        case 4:
            std::cout <<  numero1 << " * " << numero2 << " = " << numero1*numero2 << std::endl;   
            break;
        case 5:
            resultado = numero1 & numero2;
            std::cout <<  numero1 << " AND " << numero2 << " = " << resultado << std::endl;      
            break;
        case 6:
            resultado = numero1 | numero2;
            std::cout <<numero1 << " OR " << numero2 << " = " << resultado << std::endl;   
            break;
        case 7:
            resultado = numero1 ^ numero2;
            std::cout <<numero1 << " XOR " << numero2 << " = " << resultado << std::endl;   
            break;
        case 8:
            resultado = numero1 & numero2;
            std::cout <<  numero1 << " AND " << numero2 << " = " << resultado << std::endl;      
            break;
        
        default:
            std::cout << "\n Invalid Option:"<< std::endl;   
            break;
    }

    return 0;
}