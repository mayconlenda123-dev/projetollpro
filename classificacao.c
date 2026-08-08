#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "classificacao.h"
#include "util.h"

void ordenarTabela(Time times[], int totalTimes)
{
    
    for (int i = 0; i < totalTimes - 1; i++)
    {
        for (int j = 0; j < totalTimes - 1 - i; j++)
        {
            int saldoAtual = times[j].golsPro - times[j].golsContra;
            int saldoProximo = times[j + 1].golsPro - times[j + 1].golsContra;

            int trocar = 0;

            if (times[j].pontos < times[j + 1].pontos)
            {
                trocar = 1;
            }
            else if (times[j].pontos == times[j + 1].pontos &&
                     times[j].vitorias < times[j + 1].vitorias)
            {
                trocar = 1;
            }
            else if (times[j].pontos == times[j + 1].pontos &&
                     times[j].vitorias == times[j + 1].vitorias &&
                     saldoAtual < saldoProximo)
            {
                trocar = 1;
            }
            else if (times[j].pontos == times[j + 1].pontos &&
                     times[j].vitorias == times[j + 1].vitorias &&
                     saldoAtual == saldoProximo &&
                     times[j].golsPro < times[j + 1].golsPro)
            {
                trocar = 1;
            }

            if (trocar)
            {
                Time auxiliar = times[j];
                times[j] = times[j + 1];
                times[j + 1] = auxiliar;
            }
        }
    }
}

void mostrarClassificacao(Time times[], int totalTimes)
{
    if (totalTimes == 0)
    {
        printf("\nNenhum time cadastrado!\n");
        return;
    }

    int existeAtivo = 0;

    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].ativo == 1)
        {
            existeAtivo = 1;
            break;
        }
    }

    if (!existeAtivo)
    {
        printf("\nNenhum time ativo para exibir na classificação!\n");
        return;
    }

    printf("\n=========================================================================\n");
    printf("%-4s %-20s %5s %4s %4s %4s %4s %5s %5s %5s\n",
        "Pos", "Time", "Pts", "J", "V", "E", "D", "GP", "GC", "SG");
    printf("-------------------------------------------------------------------------\n");

    int posicao = 0;

    for (int i = 0; i < totalTimes; i++)
    {
        if (times[i].ativo == 1)
        {
            posicao++;

            int saldo = times[i].golsPro - times[i].golsContra;

            printf("%-4d %-20s %5d %4d %4d %4d %4d %5d %5d %5d\n",
                posicao,
                times[i].nome,
                times[i].pontos,
                times[i].jogos,
                times[i].vitorias,
                times[i].empates,
                times[i].derrotas,
                times[i].golsPro,
                times[i].golsContra,
                saldo);
        }
    }

    printf("=========================================================================\n");
}
