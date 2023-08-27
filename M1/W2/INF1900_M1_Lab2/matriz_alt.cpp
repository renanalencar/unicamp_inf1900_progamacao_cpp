
/**
 * @file matriz_alt.cpp
 *
 * @brief Programa que utilize uma matriz de caracteres
 * para simular uma tela de arte ASCII com uma dimensão inicial de 20x40.

 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>

// Função para preencher a tela com espaços em branco
void preencherTela(char **tela, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            tela[i][j] = ' ';
        }
    }
}

// Função para exibir a matriz na tela
void exibirTela(char **tela, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            std::cout << tela[i][j];
        }
        std::cout << std::endl;
    }
}

// Função para ajustar o tamanho da tela
void redimensionarTela(char **&tela, int &linhas, int &colunas, int novaLinhas, int novaColunas)
{
    // Libera a memória da matriz atual
    for (int i = 0; i < linhas; i++)
    {
        delete[] tela[i];
    }
    delete[] tela;

    // Aloca nova memória para a matriz com as novas dimensões
    tela = new char *[novaLinhas];
    for (int i = 0; i < novaLinhas; i++)
    {
        tela[i] = new char[novaColunas];
    }

    // Atualiza as dimensões da matriz
    linhas = novaLinhas;
    colunas = novaColunas;

    // Preenche a tela com espaços em branco
    preencherTela(tela, linhas, colunas);
}

void limparTela(char **tela, int linhas)
{
    // Libera a memória da matriz antes de sair do programa
    for (int i = 0; i < linhas; i++)
    {
        delete[] tela[i];
    }
    delete[] tela;
}

void mostrarMenu()
{
    std::cout << "Opções:" << std::endl;
    std::cout << "1) Desenhar" << std::endl;
    std::cout << "2) Redimensionar" << std::endl;
    std::cout << "3) Visualizar" << std::endl;
    std::cout << "4) Sair do Programa" << std::endl;
    std::cout << "Escolha uma opção: ";
}

int main()
{
    int linhas = 20;
    int colunas = 40;
    auto tela = new char *[linhas];
    for (int i = 0; i < linhas; i++)
    {
        tela[i] = new char[colunas];
    }

    preencherTela(tela, linhas, colunas);

    int opcao;

    do
    {
        mostrarMenu();
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            char caractere;
            int linha;
            int coluna;
            std::cout << "Digite o caractere que deseja desenhar: ";
            std::cin >> caractere;
            std::cout << "Digite a posição (linha coluna) onde deseja desenhar: ";
            std::cin >> linha >> coluna;

            if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
            {
                tela[linha][coluna] = caractere;
            }
            else
            {
                std::cout << "Posição inválida!" << std::endl;
            }
            break;
        }
        case 2:
        {
            int novaLinhas;
            int novaColunas;
            std::cout << "Digite a nova quantidade de linhas: ";
            std::cin >> novaLinhas;
            std::cout << "Digite a nova quantidade de colunas: ";
            std::cin >> novaColunas;

            redimensionarTela(tela, linhas, colunas, novaLinhas, novaColunas);
            break;
        }
        case 3:
            exibirTela(tela, linhas, colunas);
            break;
        case 4:
            std::cout << "Saindo do programa." << std::endl;
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    } while (opcao != 4);

    return 0;
}
