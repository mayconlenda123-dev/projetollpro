#ifndef STRUCTS_H
#define STRUCTS_H

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

#endif