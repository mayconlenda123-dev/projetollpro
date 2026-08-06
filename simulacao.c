#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "partidas.h"
#include "times.h"
#include "classificacao.h"
#include "util.h"
#include "simulacao.h"

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

void simularPartida (Partida *partida, int totalPartidas, Time times[], int totalTimes)
{
    if (partida->realizada)
    {
        return;
    }

    int indiceCasa = buscarIndiceTime(
        times,
        totalTimes,
        partida->idTimeCasa
    );

    int indiceVisitante = buscarIndiceTime(
        times,
        totalTimes,
        partida->idTimeVisitante
    );

    if (indiceCasa == -1 || indiceVisitante == -1)
    {
        return;
    }

    partida->golsCasa = rand() % 6;
    partida->golsVisitante = rand() % 6;

    partida->realizada = 1;

    atualizarEstatisticas(
        &times[indiceCasa],
        &times[indiceVisitante],
        partida->golsCasa,
        partida->golsVisitante
    );

    printf("%s %d x %d %s\n",
    times[indiceCasa].nome,
    partida->golsCasa,
    partida->golsVisitante,
    times[indiceVisitante].nome);

}

void simularRodada(
    Partida partidas[],
    int totalPartidas,
    Time times[],
    int totalTimes,
    int rodada)
{
    printf("\n==============================\n");
    printf("            RODADA %d           \n", rodada);
    printf("==============================\n\n");

    for (int i = 0; i < totalPartidas; i++)
    {
        if (partidas[i].rodada == rodada)
        {
            simularPartida(
                &partidas[i],
                totalPartidas,
                times,
                totalTimes
            );
        }
    }

    printf("\n");
}

void simularCampeonato (
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes)
{
    if (*totalPartidas == 0)
    {
        gerarConfrontos(
            partidas,
            totalPartidas,
            times,
            totalTimes
        );
    }

    for (int rodada = 1; rodada < totalTimes; rodada++){
        simularRodada(
            partidas,
            *totalPartidas,
            times,
            totalTimes,
            rodada
        );

        ordenarTabela (times, totalTimes);

        printf("\nCLASSIFICAÇÃO\n\n");
        
        mostrarClassificacao(
            times, totalTimes
        );

        pausar();
        limparTela();

    }

    printf("\n==============================\n");
    printf("CAMPEONATO ENCERRADO!\n");
    printf("==============================\n\n");

    printf("CAMPEAO: %s\n", times[0].nome);
    printf("PONTOS: %d\n", times[0].pontos);
}
