#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "times.h"
#include "jogadores.h"
#include "util.h"

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

        novo.idade = lerInteiro("Idade: ");

    } while (novo.idade <= 0);
    
    do 
    {
    
        novo.camisa = lerInteiro("Numero da camisa: ");
    
    } while (novo.camisa <= 0);

    jogadores[*totalJogadores] = novo;

    (*totalJogadores)++;

    int indiceTime = buscarIndiceTime(times, totalTimes, novo.idTime);
    if (indiceTime != -1)
    {
        times[indiceTime].quantidadeJogadores++;
    }

    printf("\nJogador cadastrado com sucesso!\n");
}

void listarJogadores (Jogador jogadores[], int totalJogadores, Time times[], int totalTimes){
    if (totalJogadores == 0)
    {
        printf("\nNão há jogadores cadastrados!\n");
        return;
    }

    printf("\n========== JOGADORES ==========\n");

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

        printf("-------------------------------------\n");

    }
}

void buscarJogador(Jogador jogadores[], int totalJogadores, Time times[], int totalTimes)
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

void alterarJogador(Jogador jogadores[], int totalJogadores, Time times[], int totalTimes)
{
    if (totalJogadores == 0)
    {
        printf("\n Nenhum jogador cadastrado!\n");
        return;
    }

    int id = lerInteiro("Digite o ID do jogador: ");

    int indice = buscarIndiceJogador (jogadores, totalJogadores, id);

    if (indice == -1)
    {
        printf("\nJogador nao encontrado!\n");
        return;
    }

    printf("\n===== DADOS ATUAIS =====\n");
    printf("Nome: %s\n", jogadores[indice].nome);
    printf("Idade: %d\n", jogadores[indice].idade);
    printf("Posicao: %s\n", jogadores[indice].posicao);
    printf("Camisa: %d\n", jogadores[indice].camisa);
    printf("ID do Time: %d\n", jogadores[indice].idTime);

    printf("\n===== NOVOS DADOS =====\n");

    lerTexto(
        "Nome: ",
        jogadores[indice].nome,
        sizeof(jogadores[indice].nome)
    );

    jogadores[indice].idade = lerInteiro("Idade: ");

    lerTexto (
        "Posicao: ",
        jogadores[indice].posicao,
        sizeof(jogadores[indice].posicao)
    );

    jogadores[indice].camisa = lerInteiro("Numero de camisa: ");

    if (confirmar("Deseja alterar o time do jogador?"))
    {
        listarTimes(times, totalTimes);

        int novoIdTime = lerInteiro ("\nNovo ID do time: ");

        int indiceNovoTime = buscarIndiceTime(times, totalTimes, novoIdTime);

        if (indiceNovoTime == -1)
        {
            printf("\nTime nao encontrado!\n");
            return;
        }

        int indiceTimeAntigo = buscarIndiceTime(times, totalTimes, jogadores[indice].idTime);

        if (indiceTimeAntigo != -1)
        {
            times[indiceTimeAntigo].quantidadeJogadores--;
        }

        times[indiceNovoTime].quantidadeJogadores++;

        jogadores[indice].idTime = novoIdTime;
    }

    printf("\nJogador alterado com sucesso!\n");
}

void removerJogador (Jogador jogadores[], int *totalJogadores, Time times[], int totalTimes)
{
    if (*totalJogadores == 0)
    {
        printf("\nNenhum jogador cadastrado!\n");
        return;
    }

    int id = lerInteiro("Digite o ID do jogador: ");

    int indice = buscarIndiceJogador (jogadores, *totalJogadores, id);
   
    if (indice == -1)
    {
        printf("\nJogador nao encontrado!\n");
        return;
    }

    if(!confirmar("Deseja realmente remover este jogador?"))
    {
        printf("\nOperacao cancelada.\n");
        return;
    }

    int indiceTime = buscarIndiceTime(times, totalTimes, jogadores[indice].idTime);

    if (indiceTime != -1 && times[indiceTime].quantidadeJogadores > 0)
    {
        times[indiceTime].quantidadeJogadores--;
    }

    for (int i = 0; i < *totalJogadores - 1;i++)
    {
        jogadores[i] = jogadores[i + 1];
    }

    (*totalJogadores)--;

    printf("\nJogador removido com sucesso!\n");

}
