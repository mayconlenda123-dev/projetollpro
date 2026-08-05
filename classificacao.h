#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"

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