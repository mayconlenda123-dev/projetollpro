#include <stdio.h>

typedef struct {
    int id;
    int rodada;
    int timeCasa;
    int timeFora;
    int golsCasa;
    int golsFora;
    int realizada;
} Partida;

typedef struct {
    int id;
    char nome[50];
    int idade;
    int camisa;
    char posicao[20];
    int idTime;
    int gols;
    int cartoesAmarelos;
    int cartoesVermelhos;
    int ativo;
} Jogador;

typedef struct {
    int id;
    char nome[50];
    char cidade[50];
    char tecnico[50];
    int quantidadeJogadores;
    int jogos;
    int vitorias;
    int empates;
    int derrotas;
    int golsPro;
    int golsContra;
    int pontos;
    int forca;
    int ativo;
} Time;

int main() {
    int opcao;

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
        "8 - Registrar Partida\n"
        "9 - Classificacao\n"
        "10 - Relatorios\n"
        "11 - Simular Campeonato\n"
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
            printf("Registrar Partida\n");
            break;

        case 9:
            printf("Classificacao\n");
            break;

        case 10:
            printf("Relatorios\n");
            break;

        case 11:
            printf("Simular Campeonato\n");
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}