/**
 * @file Laboratorio1.cpp
 *
 * @brief Threads with C++
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>
#include <thread>
#include "matriz.cpp"

int _count = 0;

void run(bool recursive)
{
    if (recursive && _count < 100) 
    {
        _count++;
        std::thread t1(run,true);
        t1.join();
    }

    srand((unsigned)time(NULL));
    int random = 1 + (rand() % 20);
    std::cout << "Ill sleep for " << random << "seconds \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(random * 1000));
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "Hello World From thread " << this_id << "! Slept for " << random << "seconds \n";
}

void atividade1() 
{
   for (size_t i = 0; i < 100; i++)
   {
     std::thread t1(run,false);
     t1.join();
   }
}

void atividade2() 
{
    std::thread t1(run,true);
    t1.join();
}
 
int main()
{
    bool end = false;
    while (!end)
    {
        std::cout << "\nEscolha uma opção: \n 1- Atividade 1 \n 2- Atividade 2 \n 3- Atividade 3 \n 4- Exit" << std::endl;
        int opcao;
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            atividade1();
            break;
        case 2:
            atividade2();
            break;
        case 3:
            matriz matrix;
            matrix.getMatriz();
            break;
        case 4:
            end = true;
            break;
        default:
            std::cout << "Opção invalida, tente novamente .." << std::endl;
        }
    }    
}