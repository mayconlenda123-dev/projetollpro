/*
 * jogadores.c
 * -----------
 * Repositorio de funcoes referentes ao CRUD de Jogadores.
 * Este arquivo NAO possui main() — ele deve ser compilado/linkado
 * junto com o arquivo principal do projeto (main.c), que contem
 * o main() e chama as funcoes abaixo.
 *
 * OBS: As structs Jogador e Time precisam ser IGUAIS as que o
 * resto do grupo esta usando no projeto (mesmo nome de campos).
 * Se ja existir um header compartilhado (ex: structs.h) com essas
 * definicoes, remova as definicoes abaixo e apenas de #include nele.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME    50
#define TAM_POSICAO 30

typedef struct {
    int  id;
    char nome[TAM_NOME];
} Time;

typedef struct {
    int  id;
    char nome[TAM_NOME];
    int  idade;
    char posicao[TAM_POSICAO];
    int  idTime;   /* referencia ao Time ao qual o jogador pertence */
} Jogador;

/* ---------- Funcoes auxiliares de entrada ---------- */

static void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

static int lerInteiro(const char *mensagem) {
    int valor;
    printf("%s", mensagem);
    while (scanf("%d", &valor) != 1) {
        printf("Entrada invalida. Digite um numero: ");
        limparBufferEntrada();
    }
    limparBufferEntrada();
    return valor;
}

static void lerTexto(const char *mensagem, char *destino, int tamanho) {
    printf("%s", mensagem);
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0'; /* remove o '\n' final */
}

/* ---------- Funcoes de Jogador ---------- */

void cadastrarJogador(Jogador jogadores[], int *totalJogadores, Time times[], int totalTimes) {
    if (totalTimes == 0) {
        printf("Nao ha times cadastrados. Cadastre um time antes de cadastrar jogadores.\n");
        return;
    }

    Jogador novo;
    novo.id = *totalJogadores + 1; /* id sequencial simples */

    lerTexto("Nome do jogador: ", novo.nome, TAM_NOME);
    novo.idade = lerInteiro("Idade: ");
    lerTexto("Posicao: ", novo.posicao, TAM_POSICAO);

    printf("\n--- Times disponiveis ---\n");
    for (int i = 0; i < totalTimes; i++) {
        printf("ID: %d | Nome: %s\n", times[i].id, times[i].nome);
    }

    int idTime = lerInteiro("Informe o ID do time do jogador: ");

    int idxTime = -1;
    for (int i = 0; i < totalTimes; i++) {
        if (times[i].id == idTime) {
            idxTime = i;
            break;
        }
    }

    if (idxTime == -1) {
        printf("Time nao encontrado! Cadastro cancelado.\n");
        return;
    }

    novo.idTime = idTime;

    jogadores[*totalJogadores] = novo;
    (*totalJogadores)++;

    printf("Jogador cadastrado com sucesso! (ID: %d)\n", novo.id);
}

void listarJogadores(Jogador jogadores[], int totalJogadores) {
    if (totalJogadores == 0) {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Jogadores ---\n");
    for (int i = 0; i < totalJogadores; i++) {
        printf("ID: %d | Nome: %s | Idade: %d | Posicao: %s | ID Time: %d\n",
               jogadores[i].id,
               jogadores[i].nome,
               jogadores[i].idade,
               jogadores[i].posicao,
               jogadores[i].idTime);
    }
}

int buscarIndiceJogador(Jogador jogadores[], int totalJogadores, int id) {
    for (int i = 0; i < totalJogadores; i++) {
        if (jogadores[i].id == id) {
            return i;
        }
    }
    return -1;
}

void buscarJogador(Jogador jogadores[], int totalJogadores) {
    int id = lerInteiro("Digite o ID do jogador que deseja buscar: ");
    int idx = buscarIndiceJogador(jogadores, totalJogadores, id);

    if (idx == -1) {
        printf("Jogador nao encontrado.\n");
        return;
    }

    printf("\n--- Jogador Encontrado ---\n");
    printf("ID: %d\n", jogadores[idx].id);
    printf("Nome: %s\n", jogadores[idx].nome);
    printf("Idade: %d\n", jogadores[idx].idade);
    printf("Posicao: %s\n", jogadores[idx].posicao);
    printf("ID Time: %d\n", jogadores[idx].idTime);
}

void alterarJogador(Jogador jogadores[], int totalJogadores) {
    int id = lerInteiro("Digite o ID do jogador que deseja alterar: ");
    int idx = buscarIndiceJogador(jogadores, totalJogadores, id);

    if (idx == -1) {
        printf("Jogador nao encontrado.\n");
        return;
    }

    printf("Deixe em branco (Enter) para manter o valor atual.\n");

    char buffer[TAM_NOME];

    printf("Nome atual: %s\n", jogadores[idx].nome);
    lerTexto("Novo nome: ", buffer, TAM_NOME);
    if (strlen(buffer) > 0) {
        strcpy(jogadores[idx].nome, buffer);
    }

    printf("Idade atual: %d\n", jogadores[idx].idade);
    printf("Nova idade (digite -1 para manter): ");
    int idade;
    scanf("%d", &idade);
    limparBufferEntrada();
    if (idade != -1) {
        jogadores[idx].idade = idade;
    }

    printf("Posicao atual: %s\n", jogadores[idx].posicao);
    lerTexto("Nova posicao: ", buffer, TAM_POSICAO);
    if (strlen(buffer) > 0) {
        strcpy(jogadores[idx].posicao, buffer);
    }

    printf("Jogador atualizado com sucesso!\n");
}

void removerJogador(Jogador jogadores[], int *totalJogadores) {
    int id = lerInteiro("Digite o ID do jogador que deseja remover: ");
    int idx = buscarIndiceJogador(jogadores, *totalJogadores, id);

    if (idx == -1) {
        printf("Jogador nao encontrado.\n");
        return;
    }

    /* desloca os elementos seguintes uma posicao para tras */
    for (int i = idx; i < *totalJogadores - 1; i++) {
        jogadores[i] = jogadores[i + 1];
    }

    (*totalJogadores)--;
    printf("Jogador removido com sucesso!\n");
}
