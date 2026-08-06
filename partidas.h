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


#endif