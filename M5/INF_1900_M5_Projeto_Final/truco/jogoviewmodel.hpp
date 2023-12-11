/**
 * @file jogoviewmodwl.hpp
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
#include "jogo.hpp"

// ViewModel simplificada para interagir entre a lógica do Jogo e a interface do usuário
class JogoViewModel {
public:
    explicit JogoViewModel(Jogo& jogo);

    void iniciarJogo();

    void jogarRodada();

    // Métodos para interação com a interface do usuário, por exemplo:
    void exibirMensagem(const std::string& mensagem) const;

private:
    Jogo& jogo;
    // Adicione mais membros conforme necessário para a interação com a interface do usuário
};
