#include <stdio.h>
#include <string.h>



#ifndef UTIL_H
#define UTIL_H

void limparBufferEntrada (void);

void limparTela(void);

void pausar(void);

int lerInteiro(char mensagem[]);

void lerTexto(char mensagem[], char texto[], int tamanho);

int confirmar(char mensagem[]);

#endif
