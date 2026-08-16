#include <stdio.h>
#include <string.h>
#include "structs.h"

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
    int totalJogadores,
    Time times[],
    int totalTimes
);

int buscarIndiceJogador(
    Jogador jogadores[],
    int totalJogadores,
    int id
);

void buscarJogador(
    Jogador jogadores[],
    int totalJogadores,
    Time times[],
    int totalTimes
);

void alterarJogador(
    Jogador jogadores[],
    int totalJogadores,
    Time times[],
    int totalTimes
);

void removerJogador(
    Jogador jogadores[],
    int *totalJogadores,
    Time times[],
    int totalTimes
);

#endif