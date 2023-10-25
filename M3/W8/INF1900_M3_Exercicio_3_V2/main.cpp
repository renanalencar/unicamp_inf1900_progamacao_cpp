/**
 * @file main.cpp
 *
 * @brief Classe com fun��o main para execu��o dos pontos da atividade.
 *
 * @author Rafael Taveira / Renan Alencar
 * Contact: rafael.t@sidi.org.br / renan.a@sidi.org.br
 *
 */

#include "main.h"

int main() {
    // Cria um recurso de texto
    Texto texto;
    FileResource<Texto> textoResource(texto);

    // L� os dados do recurso
    textoResource.ReadData();

    // Escreve os dados do recurso
    textoResource.WriteData();

    // Cria outro recurso de texto
    Texto texto2;
    FileResource<Texto> textoResource2(texto2);

    // Move o recurso para o outro objeto
    textoResource.MoveTo(textoResource2);

    // L� os dados do recurso movido
    textoResource2.ReadData();

    // Escreve os dados do recurso movido
    textoResource2.WriteData();

    // Cria um recurso de imagem
    Imagem imagem;
    FileResource<Imagem> imagemResource(imagem);

    // L� os dados do recurso
    imagemResource.ReadData();

    // Escreve os dados do recurso
    imagemResource.WriteData();

    // Cria um recurso de �udio
    Audio audio;
    FileResource<Audio> audioResource(audio);

    // L� os dados do recurso
    audioResource.ReadData();

    // Escreve os dados do recurso
    audioResource.WriteData();

    return 0;
}
