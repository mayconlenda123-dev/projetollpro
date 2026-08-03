#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "funcoes.h"

// FUNÇÕES DE TIMES
int buscarIndiceTime(Time times[], int totalTimes, int id)
{
    for (int i = 0; i < totalTimes, i++){
        if (times[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// FUNÇÕES DE JOGADORES
int buscarIndiceJogador(Jogador jogadores[], int totalJogadores, int id)
{
    for (int i = 0; i < totalJogadores; i++)
    {
        if (jogadores[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
// FUNÇÕES DE PARTIDAS
int buscarIndicePartida(Partida partidas[], int totalPartidas, int id){
    for (int i = 0; i < totalPartidas; i++){
        if(partidas[i].id == id){
            return i;
        }
    }
    return -1;
}
// FUNÇÕES DE CLASSIFICAÇÃO

// FUNÇÕES DE RELATORIO

// FUNÇÕES DE SIMULAÇÃO

// FUNÇÕES UTILITARIAS