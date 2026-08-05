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

void limparBufferEntrada(void)
{
    while(getchar() != '\n');
}

void limparTela(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar(void){
    print("Pressione ENTER para continuar");
    getchar();
}

int lerInteiro(char mensagem[]){
    int numero;

    printf("%s", mensagem);
    scanf("%d", &numero);

    limparBufferEntrada();

    return numero;
}

void lerTexto(char mensagem[], char texto[], int tamanho){
    
    printf("%s", mensagem);

    fgets(texto, tamanho, stdin);

    texto[strcspn(texto, "\n")] = '\0';
}

int confirmar(char mensagem[]){
    
    char resposta;

    printf("%s (S/N): ", mensagem);

    scanf(" %c", &resposta);

    limparBufferEntrada();

    if (resposta == 'S' || resposta == 's')
    {
        return 1;
    }

    return 0;
}


