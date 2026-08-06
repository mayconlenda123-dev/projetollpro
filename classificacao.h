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


#ifndef CLASSIFICACAO_H
#define CLASSIFICACAO_H

void ordenarTabela(
    Time times[],
    int totalTimes
);

void mostrarClassificacao(
    Time times[],
    int totalTimes
);

#endif