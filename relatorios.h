#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"

#ifndef RELATORIOS_H
#define RELATORIOS_H

void mostrarMaiorAtaque(
    Time times[],
    int totalTimes
);

void mostrarMelhorDefesa(
    Time times[],
    int totalTimes
);

void mostrarMaiorSaldo(
    Time times[],
    int totalTimes
);

void mostrarCampeao(
    Time times[],
    int totalTimes
);

void gerarRelatorios(
    Time times[],
    int totalTimes,
    Jogador jogadores[],
    int totalJogadores
);

#endif