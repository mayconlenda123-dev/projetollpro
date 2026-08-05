#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"

#ifndef JOGADORES_H
#define JOGADORES_H

void cadastrarJogador(
    Jogador jogadores[],
    int *totalJogadores,
    Time times[],
    int totalTimes
);

void listarJogadores(
    Jogador jogadores[],
    int totalJogadores
);

int buscarIndiceJogador(
    Jogador jogadores[],
    int totalJogadores,
    int id
);

void buscarJogador(
    Jogador jogadores[],
    int totalJogadores
);

void alterarJogador(
    Jogador jogadores[],
    int totalJogadores
);

void removerJogador(
    Jogador jogadores[],
    int *totalJogadores
);

#endif