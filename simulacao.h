#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"

#ifndef SIMULACAO_H
#define SIMULACAO_H

void gerarConfrontos(
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes
);

void simularRodada(
    Partida partidas[],
    int totalPartidas,
    Time times[]
);

void simularCampeonato(
    Partida partidas[],
    int totalPartidas,
    Time times[],
    int totalTimes
);

int validarConfronto(
    int indiceCasa,
    int indiceVisitante
);


#endif
