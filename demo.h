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


#ifndef DEMO_H
#define DEMO_H

extern const Time TIMES_DEMO[];

extern const int NUM_TIMES_DEMO;

extern const Jogador JOGADORES_DEMO[];

extern const int NUM_JOGADORES_DEMO;

void carregarTimesDemo(Time times[], int *totalTimes);

void carregarJogadoresDemo(Jogador jogadores[], int *totalJogadores, Time times[], int totalTimes);

void carregarDadosDemo(
    Time times[],
    int *totalTimes,
    Jogador jogadores[],
    int *totalJogadores
);

void prepararCampeonatoDemo (
    Time times[],
    int *totalTimes,
    Jogador jogadores[],
    int *totalJogadores,
    Partida partidas[],
    int *totalPartidas
);

extern const Jogador JOGADORES_DEMO_NUMERADOS[];

void preencherJogadores(
    Jogador jogadores[],
    int *totalJogadores,
    Time times[],
    int totalTimes
);

#endif
