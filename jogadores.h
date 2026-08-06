#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "partidas.h"
#include "times.h"
#include "jogadores.h"
#include "classificacao.h"
#include "util.h"
#include "simulacao.h"
#include "relatorios.h"
#include "demo.h"


#ifndef JOGADORES_H
#define JOGADORES_H

void cadastrarJogador(
    Jogador jogadores[],
    int *totalJogadores,
    Time times[],
    int totalTimes
);

void listarJogador(
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
    Time times[],
    int totalTimes
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