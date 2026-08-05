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

int buscarIndicePartida(Partida partidas[], int totalPartidas, int id){
    for (int i = 0; i < totalPartidas; i++){
        if(partidas[i].id == id){
            return i;
        }
    }
    return -1;
}

void atualizarEstatisticas(Time *casa, Time *visitante, int golsCasa, int golsVisitante)
{
    /*
======================================
Atualiza todas as estatísticas de uma
partida já finalizada.

Parâmetros:

- casa
- visitante
- golsCasa
- golsVisitante

Retorno:
Nenhum.
======================================
*/
    casa->jogos++;
    visitante->jogos++;

    casa->golsPro += golsCasa;
    casa->golsContra += golsVisitante;

    visitante->golsPro += golsVisitante;
    visitante->golsContra += golsCasa;

    if (golsCasa > golsVisitante)
    {
        casa->vitorias++;
        casa->pontos += PONTOS_VITORIA;

        visitante->derrotas++;
    }
    else if (golsCasa < golsVisitante)
    {
        visitante->vitorias++;
        visitante->pontos += PONTOS_VITORIA;

        casa->derrotas++;
    }
    else
    {
        casa->empates++;
        visitante->empates++;

        casa->pontos += PONTOS_EMPATE;
        visitante->pontos += PONTOS_EMPATE;
    }
}

void registrarPartida(Partida partidas[], int *totalPartidas, Time times[], int totalTimes)
{
    if (*totalPartidas >= MAX_PARTIDAS)
    {
        printf("Limite de partidas atingido!\n");
        return;
    }

    int idCasa, idVisitante;
    int indiceCasa, indiceVisitante;
    int golsCasa, golsVisitante;

    printf("ID do time da casa: ");
    scanf("%d", &idCasa);

    indiceCasa = buscarIndiceTime(times, totalTimes, idCasa);

    printf("ID do time visitante: ");
    scanf("%d", &idVisitante);

    indiceVisitante = buscarIndiceTime(times, totalTimes, idVisitante);

    if (!validarConfronto(indiceCasa, indiceVisitante))
    {
        printf("Confronto inválido!\n");
        return;
    }

    printf("Gols do mandante: ");
    scanf("%d", &golsCasa);

    printf("Gols do visitante: ");
    scanf("%d", &golsVisitante);

    partidas[*totalPartidas].id = *totalPartidas + 1;
    partidas[*totalPartidas].idTimeCasa = idCasa;
    partidas[*totalPartidas].idTimeVisitante = idVisitante;
    partidas[*totalPartidas].golsCasa = golsCasa;
    partidas[*totalPartidas].golsVisitante = golsVisitante;

    atualizarEstatisticas(&times[indiceCasa], &times[indiceVisitante], golsCasa, golsVisitante);

    (*totalPartidas)++;

    printf("\nPartida registrada com sucesso!\n");
}

int validarConfronto(int indiceCasa, int indiceVisitante)
{
    if (indiceCasa == -1 || indiceVisitante == -1)
    {
        return 0;
    }

    if (indiceCasa == indiceVisitante)
    {
        return 0;
    }

    return 1;
}



