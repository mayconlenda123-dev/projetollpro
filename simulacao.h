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


#ifndef SIMULACAO_H
#define SIMULACAO_H

void gerarConfrontos(
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes
);

void simularPartida(
    Partida partidas[],
    int totalPartidas,
    Time times[]
);

void simularRodada(
    Partida partidas[],
    Time times[],
    int totalTimes
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
