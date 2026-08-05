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

int buscarIndiceJogador(Jogador jogadores[], int *totalJogadores, int id)
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

void cadastrarJogador(Jogador jogadores[], int *totalJogadores, Time times[], int totalTimes)
{
    if (*totalJogadores >= MAX_JOGADORES)
    {
        printf("\nLimite de jogadores atingido!\n");
        return;
    }

    Jogador novo;

    novo.id = lerInteiro("ID do Jogador: ");

    if (buscarIndiceJogador(jogadores, *totalJogadores, novo.id) != -1)
    {
        printf("\nJa existe um jogadore com esse ID!\n");
        return;
    }

    lerTexto("Nome: ", novo.nome, sizeof(novo.nome));

    printf("\n=====  TIMES CADASTRADOS =====\n");
    listarTimes(times, totalTimes);

    novo.idTime = lerInteiro("\nID do time: ");

    if (buscarIndiceTime(times, totalTimes, novo.idTime) == -1)
    {
        printf("\nTime não encontrado!\n");
        return;
    }

    lerTexto("Posição: ", novo.posicao, sizeof (novo.posicao));
    do
    {

        novo.idade = lerIntero("Idade: ");

    } while (novo.idade <= 0);
    
    do 
    {
    
        novo.camisa = lerInteiro("Numero da camisa: ");
    
    } while (novo.camisa <= 0);

    jogadores[*totalJogadores] = novo;

    (*totalJogadores)++;

    printf("\nJogador cadastrado com sucesso!\n");
}

void listarJogadores (Jogador jogadores[], int totalJogadores, Time times[], int totalTimes){
    if (totalJogadores == 0)
    {
        printf("\nNão há jogadores cadastrados!\n");
        return
    }

    printf("\n========== JOGADORES ==========\n")

    for (int i = 0; i < totalJogadores; i++)
    {
        int indiceTime = buscarIndiceTime(times, totalTimes, jogadores[i].idTime);

        printf("\nID: %d\n", jogadores[i].id);
        printf("\nNome: %s\n", jogadores[i].nome);
        printf("\nIdade: %d\n", jogadores[i].idade);
        printf("\nCamisa: %d\n", jogadores[i].camisa);
        printf("\nPosicao: %s\n", jogadores[i].posicao);

        if (indiceTime != -1)
        {
            printf("Time: %s\n", times[indiceTime].nome);
        } else
        {
            printf("Time: Nao encontrado!\n");
        }

        printf("-------------------------------------\n")

    }
}

void buscarJogador (Jogador jogadores[], int totalJogadores, Time times[], int totalTimes)
{
    if (totalJogadores == 0)
    {
        printf("\nNenhum Jogador Cadastrado!\n");
        return;
    }

    int id = lerInteiro("Digite o ID do jogador: ");

    int indice = buscarIndiceJogador (jogadores, totalJogadores, id);

    if (indice == -1)
    {
        printf("\nJogador nao encontrado!\n");
        return;
    }

    int indiceTime = buscarIndiceTime(times, totalTimes, jogadores[indice].idTime);

    printf("\n=========== JOGADOR ==========\n");

    printf("ID: %d\n", jogadores[indice].id);
    printf("Nome: %s\n", jogadores[indice].nome);
    printf("Idade: %d\n", jogadores[indice].idade);
    printf("Camisa: %d\n", jogadores[indice].camisa);
    printf("Posicao: %s\n", jogadores[indice].posicao);

       if (indiceTime != -1)
    {
        printf("Time: %s\n", times[indiceTime].nome);
    }
    else
    {
        printf("Time: Nao encontrado\n");
    }

    printf("=============================\n");
}