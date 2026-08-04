#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "funcoes.h"

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