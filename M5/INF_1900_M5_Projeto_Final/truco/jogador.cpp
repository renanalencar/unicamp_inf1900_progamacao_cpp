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

// Verifica se o jogador possui uma determinada carta na mão
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
    // Lógica simplificada: escolhe a primeira carta da mão
    if (!mao.empty()) {
        Carta cartaJogada = mao.front();
        std::cout << nome << " jogou ";
        cartaJogada.exibirCarta();
        std::cout << std::endl;

        // Remover a carta da mão do jogador após jogar
        mao.erase(mao.begin());

        return cartaJogada;
    }
    else {
        // Se a mão estiver vazia, retorna uma carta inválida
        return Carta(0, "Inválido");
    }
}

std::string Jogador::getNome() const
{
    return nome;
}

// Adicione mais métodos conforme necessário para a lógica do jogo
