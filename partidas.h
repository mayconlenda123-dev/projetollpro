#include <stdio.h>
#include <string.h>
#include "structs.h"


#ifndef PARTIDAS_H
#define PARTIDAS_H

void registrarPartida(
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes
);

void listarPartidas(
    Partida partidas[],
    int totalPartidas,
    Time times[]
);

void atualizarEstatisticas(
    Time *casa,
    Time *visitante,
    int golsCasa,
    int golsVisitante
);


int validarConfronto(
    int indiceCasa,
    int indiceVisitante
);

#endif