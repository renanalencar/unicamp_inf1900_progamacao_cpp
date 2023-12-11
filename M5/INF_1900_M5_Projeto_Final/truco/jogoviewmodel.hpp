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

// ViewModel simplificada para interagir entre a l�gica do Jogo e a interface do usu�rio
class JogoViewModel {
public:
    explicit JogoViewModel(Jogo& jogo);

    void iniciarJogo();

    void jogarRodada();

    // M�todos para intera��o com a interface do usu�rio, por exemplo:
    void exibirMensagem(const std::string& mensagem) const;

private:
    Jogo& jogo;
    // Adicione mais membros conforme necess�rio para a intera��o com a interface do usu�rio
};
