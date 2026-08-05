#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"

#ifndef TIMES_H
#define TIMES_H


void cadastrarTime(Time times[], int *totalTimes);

void listarTimes(Time times[], int totalTimes);

int buscarIndiceTime(Time times[], int totalTimes, int id);

void buscarTime(Time times[], int totalTimes);

void alterarTime(Time times[], int totalTimes);

void removerTime(Time times[], int *totalTimes);


#endif