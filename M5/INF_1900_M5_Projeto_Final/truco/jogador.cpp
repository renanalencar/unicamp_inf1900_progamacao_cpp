/**
 * @file jogador.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#include "jogador.hpp"

Jogador::Jogador(const std::string& nome) : nome(nome) {}

void Jogador::adicionarCarta(const Carta& carta) {
    mao.push_back(carta);
}

void Jogador::exibirCartas() const {
    std::cout << nome << "'s cartas: ";
    for (const Carta& carta : mao) {
        carta.exibirCarta();
        std::cout << "  ";
    }
    std::cout << std::endl;
}

// Verifica se o jogador possui uma determinada carta na m�o
bool Jogador::possuiCarta(const Carta& carta) const {
    for (const Carta& cartaNaMao : mao) {
        if (cartaNaMao.getValor() == carta.getValor() && cartaNaMao.getNaipe() == carta.getNaipe()) {
            return true;
        }
    }
    return false;
}

// Faz um lance, escolhendo uma carta para jogar
Carta Jogador::fazerLance() {
    // L�gica simplificada: escolhe a primeira carta da m�o
    if (!mao.empty()) {
        Carta cartaJogada = mao.front();
        std::cout << nome << " jogou ";
        cartaJogada.exibirCarta();
        std::cout << std::endl;

        // Remover a carta da m�o do jogador ap�s jogar
        mao.erase(mao.begin());

        return cartaJogada;
    }
    else {
        // Se a m�o estiver vazia, retorna uma carta inv�lida
        return Carta(0, "Inv�lido");
    }
}

std::string Jogador::getNome() const
{
    return nome;
}

// Adicione mais m�todos conforme necess�rio para a l�gica do jogo
