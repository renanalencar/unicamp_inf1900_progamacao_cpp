/**
 * @file jogador.hpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#pragma once
#include <iostream>
#include <vector>
#include "carta.hpp"

class Jogador {
public:
    explicit Jogador(const std::string& nome);

    void adicionarCarta(const Carta& carta);

    void exibirCartas() const;

    // Verifica se o jogador possui uma determinada carta na mão
    bool possuiCarta(const Carta& carta) const;

    // Faz um lance, escolhendo uma carta para jogar
    Carta fazerLance();

    std::string getNome() const;

    // Adicione mais métodos conforme necessário para a lógica do jogo

private:
    std::string nome;
    std::vector<Carta> mao;
};
