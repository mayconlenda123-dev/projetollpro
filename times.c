#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "times.h"
#include "util.h"

int buscarIndiceTime(Time times[], int totalTimes, int id)
{
    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].id == id && times[i].ativo == 1)
        {
            return i;
        }
    }

    return -1;
}

void cadastrarTime(Time times[], int *totalTimes)
{
    Time novo;

    novo.id = *totalTimes + 1;

    printf("\nNome do time: ");
    scanf(" %[^\n]", novo.nome);

    printf("Cidade: ");
    scanf(" %[^\n]", novo.cidade);

    printf("Tecnico: ");
    scanf(" %[^\n]", novo.tecnico);

    do
    {
        novo.forca = lerInteiro("Forca do time (1-100): ");

    } while (novo.forca < 1 || novo.forca > 100);

    novo.quantidadeJogadores = 0;
    novo.jogos = 0;
    novo.vitorias = 0;
    novo.empates = 0;
    novo.derrotas = 0;
    novo.golsPro = 0;
    novo.golsContra = 0;
    novo.pontos = 0;
    novo.ativo = 1;

    times[*totalTimes] = novo;

    (*totalTimes)++;

    printf("\nTime cadastrado com sucesso!\n");
}

void listarTimes(Time times[], int totalTimes)
{
    if (totalTimes == 0)
    {
        printf("\nNenhum time cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].ativo == 1)
        {
            printf("\n==============================");
            printf("\nID: %d", times[i].id);
            printf("\nNome: %s", times[i].nome);
            printf("\nCidade: %s", times[i].cidade);
            printf("\nTecnico: %s", times[i].tecnico);
            printf("\nForca: %d", times[i].forca);
            printf("\nJogadores: %d", times[i].quantidadeJogadores);
            printf("\nJogos: %d", times[i].jogos);
            printf("\nPontos: %d", times[i].pontos);
            printf("\n==============================\n");
        }
    }
}

void buscarTime(Time times[], int totalTimes)
{
    int id;

    printf("Digite o ID do time: ");
    scanf("%d", &id);

    int indice = buscarIndiceTime(times, totalTimes, id);

    if (indice == -1)
    {
        printf("\nTime nao encontrado.\n");
        return;
    }

    printf("\nID: %d", times[indice].id);
    printf("\nNome: %s", times[indice].nome);
    printf("\nCidade: %s", times[indice].cidade);
    printf("\nTecnico: %s", times[indice].tecnico);
    printf("\nJogadores: %d", times[indice].quantidadeJogadores);
    printf("\nJogos: %d", times[indice].jogos);
    printf("\nVitorias: %d", times[indice].vitorias);
    printf("\nEmpates: %d", times[indice].empates);
    printf("\nDerrotas: %d", times[indice].derrotas);
    printf("\nGols Pro: %d", times[indice].golsPro);
    printf("\nGols Contra: %d", times[indice].golsContra);
    printf("\nPontos: %d", times[indice].pontos);
    printf("\nForca: %d\n", times[indice].forca);
}

void alterarTime(Time times[], int totalTimes)
{
    int id;

    printf("Digite o ID do time: ");
    scanf("%d", &id);

    int indice = buscarIndiceTime(times, totalTimes, id);

    if (indice == -1)
    {
        printf("\nTime nao encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", times[indice].nome);

    printf("Nova cidade: ");
    scanf(" %[^\n]", times[indice].cidade);

    printf("Novo tecnico: ");
    scanf(" %[^\n]", times[indice].tecnico);

    printf("Nova forca: ");
    scanf("%d", &times[indice].forca);

    printf("\nTime alterado com sucesso!\n");
}

void removerTime(Time times[], int *totalTimes)
{
    int id;

    printf("Digite o ID do time: ");
    scanf("%d", &id);

    int indice = buscarIndiceTime(times, *totalTimes, id);

    if (indice == -1)
    {
        printf("\nTime nao encontrado.\n");
        return;
    }

    times[indice].ativo = 0;

    printf("\nTime removido com sucesso!\n");
}