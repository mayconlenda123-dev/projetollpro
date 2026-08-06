#include <stdio.h>
#include <string.h>
#include "structs.h"


#ifndef SIMULACAO_H
#define SIMULACAO_H

void gerarConfrontos(
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes
);

void simularPartida(Partida *partida, Time times[], int totalTimes);

void simularRodada(
    Partida partidas[],
    int totalPartidas,
    Time times[],
    int totalTimes,
    int rodada
);

void simularCampeonato(
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes
);



#endif
