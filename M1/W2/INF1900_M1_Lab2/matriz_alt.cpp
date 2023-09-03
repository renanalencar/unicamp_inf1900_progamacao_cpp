
/**
 * @file matriz_alt.cpp
 *
 * @brief Programa que utilize uma matriz de caracteres
 * para simular uma tela de arte ASCII com uma dimensão inicial de 20x40.
 * 
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include <iostream>

void alocarMemoria(char **&tela, int linhas, int colunas);
void preencherTela(char **tela, int linhas, int colunas);
void inserirCaractere(char **tela, int linhas, int colunas, char caractere, int linha, int coluna);
void copiarMemoria(char **&de, char **&para, int linhas, int colunas);
void limparMemoria(char **tela, int linhas);
void exibirTela(char **tela, int linhas, int colunas);
void redimensionarTela(char **&tela, int &linhas, int &colunas, int novaLinhas, int novaColunas);
void mostrarMenu();

int main()
{
    int linhas = 20;
    int colunas = 40;
    char **tela;

    alocarMemoria(tela, linhas, colunas);
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

            inserirCaractere(tela, linhas, colunas, caractere, linha, coluna);
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

// Função para alocar memória para a tela
void alocarMemoria(char **&tela, int linhas, int colunas)
{
    tela = new char *[linhas];
    for (int i = 0; i < linhas; i++)
    {
        tela[i] = new char[colunas];
    }

    preencherTela(tela, linhas, colunas);
}

// Função para preencher a tela com espaços em branco
void preencherTela(char **tela, int linhas, int colunas)
{
    std::fill(tela[0], tela[linhas - 1] + colunas, ' ');
}

// Função para inserir um caractere na tela
void inserirCaractere(char **tela, int linhas, int colunas, char caractere, int linha, int coluna)
{
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
    {
        tela[linha][coluna] = caractere;
    }
    else
    {
        std::cout << "Posição inválida!" << std::endl;
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
    // 1. Cria matriz temporária
    char **temp = nullptr;
    alocarMemoria(temp, novaLinhas, novaColunas);

    // 2. Copia os valores da matriz atual para a matriz temporária
    copiarMemoria(tela, temp, std::min(linhas, novaLinhas), std::min(colunas, novaColunas));

    // 3. Libera a memória da matriz atual
    limparMemoria(tela, linhas);

    // 4. Atualiza as dimensões da matriz atual
    linhas = novaLinhas;
    colunas = novaColunas;

    // 5. Aloca nova memória para a matriz atual com as novas dimensões
    tela = nullptr;
    alocarMemoria(tela, linhas, colunas);

    // 6. Copia os valores da matriz temporária para a matriz atual
    copiarMemoria(temp, tela, linhas, colunas);

    // 7. Libera a memória da matriz temporária
    limparMemoria(temp, novaLinhas);
}

// Função para copiar a memória de uma matriz para outra
void copiarMemoria(char **&de, char **&para, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            para[i][j] = de[i][j];
        }
    }
}

void limparMemoria(char **tela, int linhas)
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
