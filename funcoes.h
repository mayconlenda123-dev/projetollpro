#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"


//FUNÇÕES DE TIMES
void cadastrarTime(Time times[], int *totalTimes);
void listarTimes(Time times[], int totalTimes);
int buscarIndiceTime(Time times[], int totalTimes, int id);
void buscarTime(Time times[], int totalTimes);
void alterarTime(Time times[], int totalTimes);
void removerTime(Time times[], int *totalTimes);

//FUNÇÕES DE JOGADORES
void cadastrarJogador(
    Jogador jogadores[],
    int *totalJogadores,
    Time times[],
    int totalTimes
);

void listarJogadores(
    Jogador jogadores[],
    int totalJogadores
);

int buscarIndiceJogador(
    Jogador jogadores[],
    int totalJogadores,
    int id
);

void buscarJogador(
    Jogador jogadores[],
    int totalJogadores
);

void alterarJogador(
    Jogador jogadores[],
    int totalJogadores
);

void removerJogador(
    Jogador jogadores[],
    int *totalJogadores
);

//FUNÇÕES DE PARTIDAS
void registrarPartida(
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes
);

void listarPartidas(
    Partida partidas[],
    int totalPartidas,
    Time times[]
);

void atualizarEstatisticas(
    Time *casa,
    Time *visitante,
    int golsCasa,
    int golsVisitante
);

//FUNÇÕES DE CLASSIFICAÇÃO
void ordenarTabela(
    Time times[],
    int totalTimes
);

void mostrarClassificacao(
    Time times[],
    int totalTimes
);

//FUNÇÕES DE RELATORIO
void mostrarMaiorAtaque(
    Time times[],
    int totalTimes
);

void mostrarMelhorDefesa(
    Time times[],
    int totalTimes
);

void mostrarMaiorSaldo(
    Time times[],
    int totalTimes
);

void mostrarCampeao(
    Time times[],
    int totalTimes
);

void gerarRelatorios(
    Time times[],
    int totalTimes,
    Jogador jogadores[],
    int totalJogadores
);

//FUNÇÕES DE SIMULAÇÃO
void gerarConfrontos(
    Partida partidas[],
    int *totalPartidas,
    Time times[],
    int totalTimes
);

void simularRodada(
    Partida partidas[],
    int totalPartidas,
    Time times[]
);

void simularCampeonato(
    Partida partidas[],
    int totalPartidas,
    Time times[],
    int totalTimes
);

//FUNÇÕES UTILITARIAS
void limparTela();

void pausar();

int lerInteiro(char mensagem[]);

void lerTexto(char mensagem[], char texto[], int tamanho);

int confirmar(char mensagem[]);