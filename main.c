#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "funcoes.h"
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
            "8 - Preparar Campeonato Demo"
            "9 - Registrar Partida\n"
            "10 - Classificacao\n"
            "11 - Relatorios\n"
            "12 - Simular Campeonato\n"
            "0 - Sair\n\n"
            "Digite sua escolha: "
        );

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Cadastrar Time\n");
                break;

            case 2:
                printf("Listar Times\n");
                break;

            case 3:
                printf("Buscar Time\n");
                break;

            case 4:
                printf("Alterar Time\n");
                break;

            case 5:
                printf("Remover Time\n");
                break;

            case 6:
                printf("Cadastrar Jogador\n");
                break;

            case 7:
                printf("Listar Jogadores\n");
                break;
            
            case 8:
                prepararCampeonatoDemo(times, &totalTimes, jogadores, &totalJogadores, partidas, &totalPartidas);
                break;

            case 9:
                printf("Registrar Partida\n");
                break;

            case 10:
                printf("Classificacao\n");
                break;

            case 11:
                printf("Relatorios\n");
                break;

            case 12:
                printf("Simular Campeonato\n");
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