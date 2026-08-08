#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "util.h"
#include "relatorios.h"

int buscarIndiceMelhorClassificado(Time times[], int totalTimes)
{

    int indiceMelhor = -1;

    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].ativo != 1)
        {
            continue;
        }

        if (indiceMelhor == -1)
        {
            indiceMelhor = i;
            continue;
        }

        int saldoAtual = times[i].golsPro - times[i].golsContra;
        int saldoMelhor = times[indiceMelhor].golsPro - times[indiceMelhor].golsContra;

        if (times[i].pontos > times[indiceMelhor].pontos)
        {
            indiceMelhor = i;
        }
        else if (times[i].pontos == times[indiceMelhor].pontos &&
                 times[i].vitorias > times[indiceMelhor].vitorias)
        {
            indiceMelhor = i;
        }
        else if (times[i].pontos == times[indiceMelhor].pontos &&
                 times[i].vitorias == times[indiceMelhor].vitorias &&
                 saldoAtual > saldoMelhor)
        {
            indiceMelhor = i;
        }
        else if (times[i].pontos == times[indiceMelhor].pontos &&
                 times[i].vitorias == times[indiceMelhor].vitorias &&
                 saldoAtual == saldoMelhor &&
                 times[i].golsPro > times[indiceMelhor].golsPro)
        {
            indiceMelhor = i;
        }
    }

    return indiceMelhor;
}

void mostrarMaiorAtaque(Time times[], int totalTimes)
{
    int indiceMelhor = -1;

    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].ativo != 1)
        {
            continue;
        }

        if (indiceMelhor == -1 || times[i].golsPro > times[indiceMelhor].golsPro)
        {
            indiceMelhor = i;
        }
    }

    if (indiceMelhor == -1)
    {
        printf("\nNenhum time ativo cadastrado!\n");
        return;
    }

    printf("\n===== MAIOR ATAQUE =====\n");
    printf("Time: %s\n", times[indiceMelhor].nome);
    printf("Gols Pro: %d\n", times[indiceMelhor].golsPro);
    printf("=========================\n");
}

void mostrarMelhorDefesa(Time times[], int totalTimes)
{
    int indiceMelhor = -1;

    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].ativo != 1)
        {
            continue;
        }

        if (indiceMelhor == -1 || times[i].golsContra < times[indiceMelhor].golsContra)
        {
            indiceMelhor = i;
        }
    }

    if (indiceMelhor == -1)
    {
        printf("\nNenhum time ativo cadastrado!\n");
        return;
    }

    printf("\n===== MELHOR DEFESA =====\n");
    printf("Time: %s\n", times[indiceMelhor].nome);
    printf("Gols Contra: %d\n", times[indiceMelhor].golsContra);
    printf("==========================\n");
}

void mostrarMaiorSaldo(Time times[], int totalTimes)
{
    int indiceMelhor = -1;
    int melhorSaldo = 0;

    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].ativo != 1)
        {
            continue;
        }

        int saldo = times[i].golsPro - times[i].golsContra;

        if (indiceMelhor == -1 || saldo > melhorSaldo)
        {
            indiceMelhor = i;
            melhorSaldo = saldo;
        }
    }

    if (indiceMelhor == -1)
    {
        printf("\nNenhum time ativo cadastrado!\n");
        return;
    }

    printf("\n===== MAIOR SALDO DE GOLS =====\n");
    printf("Time: %s\n", times[indiceMelhor].nome);
    printf("Saldo: %d\n", melhorSaldo);
    printf("================================\n");
}

void mostrarCampeao(Time times[], int totalTimes)
{
    int indiceMelhor = buscarIndiceMelhorClassificado(times, totalTimes);

    if (indiceMelhor == -1)
    {
        printf("\nNenhum time ativo cadastrado!\n");
        return;
    }

    printf("\n===== CAMPEAO =====\n");
    printf("Time: %s\n", times[indiceMelhor].nome);
    printf("Pontos: %d\n", times[indiceMelhor].pontos);
    printf("Vitorias: %d\n", times[indiceMelhor].vitorias);
    printf("Saldo de Gols: %d\n", times[indiceMelhor].golsPro - times[indiceMelhor].golsContra);
    printf("====================\n");
}

void gerarRelatorios(Time times[], int totalTimes, Jogador jogadores[], int totalJogadores)
{
    if (totalTimes == 0)
    {
        printf("\nNenhum time cadastrado!\n");
        return;
    }

    int opcao;

    do
    {
        printf(
            "\n========== RELATORIOS ==========\n"
            "1 - Maior Ataque\n"
            "2 - Melhor Defesa\n"
            "3 - Maior Saldo de Gols\n"
            "4 - Campeao\n"
            "5 - Resumo Geral do Campeonato\n"
            "0 - Voltar\n\n"
            "Digite sua escolha: "
        );

        opcao = lerInteiro("");

        switch (opcao)
        {
            case 1:
                mostrarMaiorAtaque(times, totalTimes);
                break;

            case 2:
                mostrarMelhorDefesa(times, totalTimes);
                break;

            case 3:
                mostrarMaiorSaldo(times, totalTimes);
                break;

            case 4:
                mostrarCampeao(times, totalTimes);
                break;

            case 5:
                printf("\n===== RESUMO GERAL =====\n");
                printf("Times cadastrados: %d\n", totalTimes);
                printf("Jogadores cadastrados: %d\n", totalJogadores);
                mostrarMaiorAtaque(times, totalTimes);
                mostrarMelhorDefesa(times, totalTimes);
                mostrarMaiorSaldo(times, totalTimes);
                mostrarCampeao(times, totalTimes);
                break;

            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 0);
}
