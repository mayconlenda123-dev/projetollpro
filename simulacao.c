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

void gerarConfrontos(Partida partidas[], int *totalPartidas, Time times[], int totalTimes)
{

    if (totalTimes % 2 != 0)
    {
        printf("A quantidade de times deve ser par!\n");
        return;
    }

    int ordem[MAX_TIMES];

    for (int i = 0; i < totalTimes; i++)
    {
        ordem[i] = i;
    }
    for (int rodada = 1; rodada < totalTimes; rodada++)
    {
        for (int i = 0; i < totalTimes / 2; i++)
        {
            int casa = ordem[i];
            int visitante = ordem[totalTimes - 1 - i];
            Partida *nova = &partidas[*totalPartidas];
            nova->id = *totalPartidas + 1;
            nova->rodada = rodada;
            nova->idTimeCasa = times[casa].id;
            nova->idTimeVisitante = times[visitante].id;
            nova->golsCasa = -1;
            nova->golsVisitante = -1;
            nova->realizada = 0;

            (*totalPartidas)++;
        }

        int ultimo = ordem[totalTimes -1];

        for (int i = totalTimes - 1;i > 1; i--){
            ordem[i] = ordem[i - 1];
        }

        ordem[1] = ultimo;
    }
}