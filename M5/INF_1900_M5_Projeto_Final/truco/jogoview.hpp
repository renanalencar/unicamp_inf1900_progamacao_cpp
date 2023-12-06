/**
 * @file jogoview.cpp
 *
 * @brief Jogo de Truco - Projeto Final.
 *
 * @author Anderson Silva, Rafael Taveira, Renan Alencar, and Wanderson Medeiros
 * Contact: {a.matheus, rafael.t, renan.a, w.ricardo} at sidi.org.br
 *
 */

#pragma once
#include <iostream>
#include <string>
#include "jogoviewmodel.hpp"

// Classe JogoView simplificada para interagir com o usuário via linha de comando
class JogoView {
public:
    explicit JogoView(JogoViewModel& viewModel);

    void iniciar();

private:
    JogoViewModel& viewModel;

    void exibirMenu() const;

    void processarOpcao(int opcao);
};