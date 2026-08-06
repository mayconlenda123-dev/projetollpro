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

#define JOGADORES_POR_TIME 11
#define NUM_JOGADORES_DEMO (NUM_TIMES_DEMO * JOGADORES_POR_TIME)
#define TIME_DEMO(id, nome, forca) \
    {id, nome,forca, "", "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}

const Time TIMES_DEMO[] =
    {
        TIME_DEMO(1, "Barcelona",96),
        TIME_DEMO(2, "Liverpool",91),
        TIME_DEMO(3, "Real Madrid",92),
        TIME_DEMO(4, "Milan",85),
        TIME_DEMO(5, "PSG",94),
        TIME_DEMO(6, "Bayern München",93),
        TIME_DEMO(7, "Arsenal",93),
        TIME_DEMO(8, "Manchester City",92),
        TIME_DEMO(9, "Manchester United",85),
        TIME_DEMO(10, "Chelsea",86),
        TIME_DEMO(11, "Juventus",86),
        TIME_DEMO(12, "Roma",80),};

// Struct Jogador (ver structs.h): { id, nome, idade, camisa, posicao, idTime, gols, cartoesAmarelos, cartoesVermelhos, ativo }
const Jogador JOGADORES_DEMO[] =
    {
        // ======================
        // Barcelona
        // ======================

        {1, "Marc-Andre ter Stegen", 33, 1, "GK", 1, 0, 0, 0, 1},
        {2, "Jules Kounde", 26, 23, "LD", 1, 0, 0, 0, 1},
        {3, "Pau Cubarsi", 18, 2, "ZAG", 1, 0, 0, 0, 1},
        {4, "Inigo Martinez", 34, 25, "ZAG", 1, 0, 0, 0, 1},
        {5, "Alejandro Balde", 22, 3, "LE", 1, 0, 0, 0, 1},
        {6, "Frenkie de Jong", 28, 21, "VOL", 1, 0, 0, 0, 1},
        {7, "Pedri", 23, 8, "MC", 1, 0, 0, 0, 1},
        {8, "Lamine Yamal", 18, 10, "PD", 1, 0, 0, 0, 1},
        {9, "Dani Olmo", 27, 20, "MEI", 1, 0, 0, 0, 1},
        {10, "Raphinha", 29, 11, "PE", 1, 0, 0, 0, 1},
        {11, "Robert Lewandowski", 37, 9, "CA", 1, 0, 0, 0, 1},

        // ======================
        // Liverpool
        // ======================

        {12, "Alisson Becker", 34, 1, "GK", 2, 0, 0, 0, 1},
        {13, "Jeremie Frimpong", 25, 30, "LD", 2, 0, 0, 0, 1},
        {14, "Virgil van Dijk", 34, 4, "ZAG", 2, 0, 0, 0, 1},
        {15, "Ibrahima Konate", 26, 5, "ZAG", 2, 0, 0, 0, 1},
        {16, "Milos Kerkez", 22, 26, "LE", 2, 0, 0, 0, 1},
        {17, "Ryan Gravenberch", 24, 38, "VOL", 2, 0, 0, 0, 1},
        {18, "Alexis Mac Allister", 27, 10, "MC", 2, 0, 0, 0, 1},
        {19, "Mohamed Salah", 34, 11, "PD", 2, 0, 0, 0, 1},
        {20, "Florian Wirtz", 23, 7, "MEI", 2, 0, 0, 0, 1},
        {21, "Cody Gakpo", 27, 18, "PE", 2, 0, 0, 0, 1},
        {22, "Hugo Ekitike", 24, 9, "CA", 2, 0, 0, 0, 1},

        // ======================
        // Real Madrid
        // ======================

        {23, "Thibaut Courtois", 34, 1, "GK", 3, 0, 0, 0, 1},
        {24, "Trent Alexander-Arnold", 27, 12, "LD", 3, 0, 0, 0, 1},
        {25, "Antonio Rudiger", 33, 22, "ZAG", 3, 0, 0, 0, 1},
        {26, "Dean Huijsen", 21, 24, "ZAG", 3, 0, 0, 0, 1},
        {27, "Fran Garcia", 27, 20, "LE", 3, 0, 0, 0, 1},
        {28, "Aurelien Tchouameni", 26, 18, "VOL", 3, 0, 0, 0, 1},
        {29, "Federico Valverde", 28, 15, "MC", 3, 0, 0, 0, 1},
        {30, "Arda Guler", 21, 19, "MEI", 3, 0, 0, 0, 1},
        {31, "Rodrygo", 26, 11, "PD", 3, 0, 0, 0, 1},
        {32, "Vinicius Junior", 26, 7, "PE", 3, 0, 0, 0, 1},
        {33, "Kylian Mbappe", 28, 9, "CA", 3, 0, 0, 0, 1},

        // ======================
        // Milan
        // ======================

        {34, "Mike Maignan", 31, 16, "GK", 4, 0, 0, 0, 1},
        {35, "Alex Jimenez", 21, 26, "LD", 4, 0, 0, 0, 1},
        {36, "Fikayo Tomori", 28, 23, "ZAG", 4, 0, 0, 0, 1},
        {37, "Strahinja Pavlovic", 25, 5, "ZAG", 4, 0, 0, 0, 1},
        {38, "Pervis Estupinan", 28, 4, "LE", 4, 0, 0, 0, 1},
        {39, "Youssouf Fofana", 27, 20, "VOL", 4, 0, 0, 0, 1},
        {40, "Samuele Ricci", 24, 28, "MC", 4, 0, 0, 0, 1},
        {41, "Christian Pulisic", 28, 11, "PD", 4, 0, 0, 0, 1},
        {42, "Luka Modric", 41, 14, "MEI", 4, 0, 0, 0, 1},
        {43, "Rafael Leao", 27, 10, "PE", 4, 0, 0, 0, 1},
        {44, "Santiago Gimenez", 25, 7, "CA", 4, 0, 0, 0, 1},

        // ======================
        // PSG
        // ======================

        {45, "Gianluigi Donnarumma", 27, 50, "GK", 5, 0, 0, 0, 1},
        {46, "Achraf Hakimi", 28, 2, "LD", 5, 0, 0, 0, 1},
        {47, "Marquinhos", 32, 5, "ZAG", 5, 0, 0, 0, 1},
        {48, "Willian Pacho", 25, 3, "ZAG", 5, 0, 0, 0, 1},
        {49, "Nuno Mendes", 24, 25, "LE", 5, 0, 0, 0, 1},
        {50, "Joao Neves", 21, 87, "VOL", 5, 0, 0, 0, 1},
        {51, "Vitinha", 26, 17, "MC", 5, 0, 0, 0, 1},
        {52, "Desire Doue", 21, 14, "MEI", 5, 0, 0, 0, 1},
        {53, "Khvicha Kvaratskhelia", 25, 7, "PE", 5, 0, 0, 0, 1},
        {54, "Ousmane Dembele", 29, 10, "PD", 5, 0, 0, 0, 1},
        {55, "Goncalo Ramos", 25, 9, "CA", 5, 0, 0, 0, 1},

        // ======================
        // Bayern München
        // ======================

        {56, "Manuel Neuer", 40, 1, "GK", 6, 0, 0, 0, 1},
        {57, "Konrad Laimer", 29, 27, "LD", 6, 0, 0, 0, 1},
        {58, "Dayot Upamecano", 27, 2, "ZAG", 6, 0, 0, 0, 1},
        {59, "Kim Min-jae", 30, 3, "ZAG", 6, 0, 0, 0, 1},
        {60, "Alphonso Davies", 26, 19, "LE", 6, 0, 0, 0, 1},
        {61, "Joshua Kimmich", 32, 6, "VOL", 6, 0, 0, 0, 1},
        {62, "Aleksandar Pavlovic", 22, 25, "MC", 6, 0, 0, 0, 1},
        {63, "Jamal Musiala", 23, 42, "MEI", 6, 0, 0, 0, 1},
        {64, "Michael Olise", 24, 10, "PD", 6, 0, 0, 0, 1},
        {65, "Kingsley Coman", 30, 11, "PE", 6, 0, 0, 0, 1},
        {66, "Harry Kane", 33, 9, "CA", 6, 0, 0, 0, 1},

        // ======================
        // Arsenal
        // ======================

        {67, "David Raya", 31, 1, "GK", 7, 0, 0, 0, 1},
        {68, "Ben White", 29, 4, "LD", 7, 0, 0, 0, 1},
        {69, "William Saliba", 25, 2, "ZAG", 7, 0, 0, 0, 1},
        {70, "Gabriel Magalhaes", 28, 6, "ZAG", 7, 0, 0, 0, 1},
        {71, "Riccardo Calafiori", 24, 33, "LE", 7, 0, 0, 0, 1},
        {72, "Martin Zubimendi", 27, 36, "VOL", 7, 0, 0, 0, 1},
        {73, "Declan Rice", 28, 41, "MC", 7, 0, 0, 0, 1},
        {74, "Martin Odegaard", 28, 8, "MEI", 7, 0, 0, 0, 1},
        {75, "Bukayo Saka", 25, 7, "PD", 7, 0, 0, 0, 1},
        {76, "Gabriel Martinelli", 25, 11, "PE", 7, 0, 0, 0, 1},
        {77, "Viktor Gyokeres", 28, 14, "CA", 7, 0, 0, 0, 1},

        // ======================
        // Manchester City
        // ======================

        {78, "Ederson", 33, 31, "GK", 8, 0, 0, 0, 1},
        {79, "Rico Lewis", 22, 82, "LD", 8, 0, 0, 0, 1},
        {80, "Ruben Dias", 29, 3, "ZAG", 8, 0, 0, 0, 1},
        {81, "Josko Gvardiol", 25, 24, "ZAG", 8, 0, 0, 0, 1},
        {82, "Rayan Ait-Nouri", 25, 62, "LE", 8, 0, 0, 0, 1},
        {83, "Rodri", 30, 16, "VOL", 8, 0, 0, 0, 1},
        {84, "Tijjani Reijnders", 28, 4, "MC", 8, 0, 0, 0, 1},
        {85, "Phil Foden", 26, 47, "MEI", 8, 0, 0, 0, 1},
        {86, "Savinho", 22, 26, "PD", 8, 0, 0, 0, 1},
        {87, "Jeremy Doku", 24, 11, "PE", 8, 0, 0, 0, 1},
        {88, "Erling Haaland", 26, 9, "CA", 8, 0, 0, 0, 1},

        // ======================
        // Manchester United
        // ======================

        {89, "Andre Onana", 30, 24, "GK", 9, 0, 0, 0, 1},
        {90, "Noussair Mazraoui", 28, 3, "LD", 9, 0, 0, 0, 1},
        {91, "Matthijs de Ligt", 26, 4, "ZAG", 9, 0, 0, 0, 1},
        {92, "Lisandro Martinez", 28, 6, "ZAG", 9, 0, 0, 0, 1},
        {93, "Patrick Dorgu", 21, 13, "LE", 9, 0, 0, 0, 1},
        {94, "Manuel Ugarte", 25, 25, "VOL", 9, 0, 0, 0, 1},
        {95, "Bruno Fernandes", 32, 8, "MC", 9, 0, 0, 0, 1},
        {96, "Mason Mount", 28, 7, "MEI", 9, 0, 0, 0, 1},
        {97, "Amad Diallo", 24, 16, "PD", 9, 0, 0, 0, 1},
        {98, "Matheus Cunha", 27, 10, "PE", 9, 0, 0, 0, 1},
        {99, "Rasmus Hojlund", 23, 11, "CA", 9, 0, 0, 0, 1},

        // ======================
        // Chelsea
        // ======================

        {100, "Robert Sanchez", 29, 1, "GK", 10, 0, 0, 0, 1},
        {101, "Reece James", 27, 24, "LD", 10, 0, 0, 0, 1},
        {102, "Levi Colwill", 23, 6, "ZAG", 10, 0, 0, 0, 1},
        {103, "Wesley Fofana", 25, 5, "ZAG", 10, 0, 0, 0, 1},
        {104, "Marc Cucurella", 28, 3, "LE", 10, 0, 0, 0, 1},
        {105, "Moises Caicedo", 25, 25, "VOL", 10, 0, 0, 0, 1},
        {106, "Enzo Fernandez", 25, 8, "MC", 10, 0, 0, 0, 1},
        {107, "Cole Palmer", 24, 20, "MEI", 10, 0, 0, 0, 1},
        {108, "Pedro Neto", 26, 7, "PD", 10, 0, 0, 0, 1},
        {109, "Jamie Gittens", 22, 11, "PE", 10, 0, 0, 0, 1},
        {110, "Joao Pedro", 25, 9, "CA", 10, 0, 0, 0, 1},

        // ======================
        // Juventus
        // ======================

        {111, "Michele Di Gregorio", 29, 29, "GK", 11, 0, 0, 0, 1},
        {112, "Timothy Weah", 26, 22, "LD", 11, 0, 0, 0, 1},
        {113, "Pierre Kalulu", 26, 15, "ZAG", 11, 0, 0, 0, 1},
        {114, "Bremer", 29, 3, "ZAG", 11, 0, 0, 0, 1},
        {115, "Andrea Cambiaso", 26, 27, "LE", 11, 0, 0, 0, 1},
        {116, "Manuel Locatelli", 28, 5, "VOL", 11, 0, 0, 0, 1},
        {117, "Khephren Thuram", 25, 19, "MC", 11, 0, 0, 0, 1},
        {118, "Teun Koopmeiners", 28, 8, "MEI", 11, 0, 0, 0, 1},
        {119, "Francisco Conceicao", 23, 7, "PD", 11, 0, 0, 0, 1},
        {120, "Kenan Yildiz", 21, 10, "PE", 11, 0, 0, 0, 1},
        {121, "Jonathan David", 26, 9, "CA", 11, 0, 0, 0, 1},

        // ======================
        // Roma
        // ======================

        {122, "Mile Svilar", 27, 99, "GK", 12, 0, 0, 0, 1},
        {123, "Zeki Celik", 29, 19, "LD", 12, 0, 0, 0, 1},
        {124, "Gianluca Mancini", 30, 23, "ZAG", 12, 0, 0, 0, 1},
        {125, "Evan Ndicka", 26, 4, "ZAG", 12, 0, 0, 0, 1},
        {126, "Angelino", 29, 3, "LE", 12, 0, 0, 0, 1},
        {127, "Bryan Cristante", 31, 4, "VOL", 12, 0, 0, 0, 1},
        {128, "Manu Kone", 25, 17, "MC", 12, 0, 0, 0, 1},
        {129, "Paulo Dybala", 33, 21, "MEI", 12, 0, 0, 0, 1},
        {130, "Matias Soule", 23, 11, "PD", 12, 0, 0, 0, 1},
        {131, "Lorenzo Pellegrini", 30, 7, "PE", 12, 0, 0, 0, 1},
        {132, "Artem Dovbyk", 29, 9, "CA", 12, 0, 0, 0, 1},
};

const int NUM_TIMES_DEMO = sizeof(TIMES_DEMO) / sizeof(TIMES_DEMO[0]);

void carregarTimesDemo(Time times[], int *totalTimes)
{
    for (int i = 0; i < NUM_TIMES_DEMO; i++)
    {
        times[i] = TIMES_DEMO[i];
    }

    *totalTimes = NUM_TIMES_DEMO;
}

void carregarJogadoresDemo(Jogador jogadores[], int *totalJogadores)
{
    for (int i = 0; i < NUM_JOGADORES_DEMO; i++)
    {
        jogadores[i] = JOGADORES_DEMO[i];
    }

    *totalJogadores = NUM_JOGADORES_DEMO;
}

void carregarDadosDemo(
    Time times[],
    int *totalTimes,
    Jogador jogadores[],
    int *totalJogadores)
{
    carregarTimesDemo(times, totalTimes);

    carregarJogadoresDemo(jogadores, totalJogadores);

    printf("\n=== Dados de demonstração carregados com sucesso! ===\n");
    printf("Times carregados: %d\n", *totalTimes);
    printf("Jogadores carregados: %d\n\n", *totalJogadores);
}

void prepararCampeonatoDemo(Time times[], int *totalTimes, Jogador jogadores[], int *totalJogadores, Partida partidas[], int *totalPartidas)
{
    carregarTimesDemo(times, totalTimes);

    carregarJogadoresDemo(jogadores, totalJogadores);

    gerarConfrontos(partidas, totalPartidas, times, *totalTimes);

    printf("\n====================================\n");
    printf(" CAMPEONATO DEMO PREPARADO\n");
    printf("====================================\n");
    printf("Times: %d\n", *totalTimes);
    printf("Jogadores: %d\n", *totalJogadores);
    printf("Partidas: %d\n", *totalPartidas);
    printf("====================================\n");
}
