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
#include "demo.h"

int main() {
    int opcao;

    Time times[MAX_TIMES];
    Jogador jogadores[MAX_JOGADORES];
    Partida partidas[MAX_PARTIDAS];

    int totalTimes = 0;
    int totalJogadores = 0;
    int totalPartidas = 0;


    do{
        printf(
            "==========================\n"
            "    SISTEMA DE CAMPEONATO\n"
            "==========================\n\n"
            "1 - Cadastrar Time\n"
            "2 - Listar Times\n"
            "3 - Buscar Time\n"
            "4 - Alterar Time\n"
            "5 - Remover Time\n"
            "6 - Cadastrar Jogador\n"
            "7 - Listar Jogadores\n"
            "8 - Buscar Jogadores\n"
            "9 - Alterar Jogadores\n"
            "10 - Remover Jogadores\n"
            "11 - Preparar Campeonato Demo\n"
            "12 - Registrar Partida\n"
            "13 - Classificacao\n"
            "14 - Relatorios\n"
            "15 - Simular Campeonato\n"
            "0 - Sair\n\n"
            "Digite sua escolha: "
        );

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTime (times, &totalTimes);
                break;

            case 2:
                listarTimes(times, totalTimes);
                break;

            case 3:
                buscarTime (times, totalTimes);
                break;

            case 4:
                alterarTime (times, totalTimes);
                break;

            case 5:
                removerTime (times, &totalTimes);
                break;

            case 6:
                cadastrarJogador (jogadores, &totalJogadores, times, totalTimes);
                break;

            case 7:
                listarJogadores (jogadores ,totalJogadores, times, totalTimes);
                break;

            case 8:
                buscarJogador (jogadores, totalJogadores, times, totalTimes );
                break;

            case 9:
                alterarJogador (jogadores, totalJogadores, times, totalTimes);
                break;

            case 10:
                removerJogador (jogadores, &totalJogadores);
                break;

            case 11:
                prepararCampeonatoDemo(times, &totalTimes, jogadores, &totalJogadores, partidas, &totalPartidas);
                break;

            case 12:
                registrarPartida (partidas, &totalPartidas, times, totalTimes);
                break;

            case 13:
                mostrarClassificacao (times, totalTimes);
                break;

            case 14:
                gerarRelatorios (times, totalTimes, jogadores, totalJogadores);
                break;

            case 15:
                simularCampeonato (partidas, &totalPartidas, times, totalTimes);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}