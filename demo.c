#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "constantes.h"
#include "funcoes.h"
#include "demo.h"

#define JOGADORES_POR_TIME 11
#define NUM_JOGADORES_DEMO (NUM_TIMES_DEMO * JOGADORES_POR_TIME)
#define TIME_DEMO(id, nome) \
    {id, nome, 0, 0, 0, 0, 0, 0, 0, 0}

const Time TIMES_DEMO[] =
    {
        TIME_DEMO(1, "Barcelona"),
        TIME_DEMO(2, "Liverpool"),
        TIME_DEMO(3, "Real Madrid"),
        TIME_DEMO(4, "Milan"),
        TIME_DEMO(5, "PSG"),
        TIME_DEMO(6, "Bayern München"),
        TIME_DEMO(7, "Arsenal"),
        TIME_DEMO(8, "Manchester City"),
        TIME_DEMO(9, "Manchester United"),
        TIME_DEMO(10, "Chelsea"),
        TIME_DEMO(11, "Juventus"),
        TIME_DEMO(12, "Roma")};

const Jogador JOGADORES_DEMO[] =
    {
        // ======================
        // Barcelona
        // ======================

        {1, "Marc-Andre ter Stegen", 33, "GK", 1},
        {2, "Jules Kounde", 26, "LD", 1},
        {3, "Pau Cubarsi", 18, "ZAG", 1},
        {4, "Inigo Martinez", 34, "ZAG", 1},
        {5, "Alejandro Balde", 22, "LE", 1},
        {6, "Frenkie de Jong", 28, "VOL", 1},
        {7, "Pedri", 23, "MC", 1},
        {8, "Lamine Yamal", 18, "PD", 1},
        {9, "Dani Olmo", 27, "MEI", 1},
        {10, "Raphinha", 29, "PE", 1},
        {11, "Robert Lewandowski", 37, "CA", 1},

        // ======================
        // Liverpool
        // ======================

        {12, "Alisson Becker", 34, "GK", 2},
        {13, "Jeremie Frimpong", 25, "LD", 2},
        {14, "Virgil van Dijk", 34, "ZAG", 2},
        {15, "Ibrahima Konate", 26, "ZAG", 2},
        {16, "Milos Kerkez", 22, "LE", 2},
        {17, "Ryan Gravenberch", 24, "VOL", 2},
        {18, "Alexis Mac Allister", 27, "MC", 2},
        {19, "Mohamed Salah", 34, "PD", 2},
        {20, "Florian Wirtz", 23, "MEI", 2},
        {21, "Cody Gakpo", 27, "PE", 2},
        {22, "Hugo Ekitike", 24, "CA", 2},

        // ======================
        // Real Madrid
        // ======================

        {23, "Thibaut Courtois", 34, "GK", 3},
        {24, "Trent Alexander-Arnold", 27, "LD", 3},
        {25, "Antonio Rudiger", 33, "ZAG", 3},
        {26, "Dean Huijsen", 21, "ZAG", 3},
        {27, "Fran Garcia", 27, "LE", 3},
        {28, "Aurelien Tchouameni", 26, "VOL", 3},
        {29, "Federico Valverde", 28, "MC", 3},
        {30, "Arda Guler", 21, "MEI", 3},
        {31, "Rodrygo", 26, "PD", 3},
        {32, "Vinicius Junior", 26, "PE", 3},
        {33, "Kylian Mbappe", 28, "CA", 3},

        // ======================
        // Milan
        // ======================

        {34, "Mike Maignan", 31, "GK", 4},
        {35, "Alex Jimenez", 21, "LD", 4},
        {36, "Fikayo Tomori", 28, "ZAG", 4},
        {37, "Strahinja Pavlovic", 25, "ZAG", 4},
        {38, "Pervis Estupinan", 28, "LE", 4},
        {39, "Youssouf Fofana", 27, "VOL", 4},
        {40, "Samuele Ricci", 24, "MC", 4},
        {41, "Christian Pulisic", 28, "PD", 4},
        {42, "Luka Modric", 41, "MEI", 4},
        {43, "Rafael Leao", 27, "PE", 4},
        {44, "Santiago Gimenez", 25, "CA", 4},

        // ======================
        // PSG
        // ======================

        {45, "Gianluigi Donnarumma", 27, "GK", 5},
        {46, "Achraf Hakimi", 28, "LD", 5},
        {47, "Marquinhos", 32, "ZAG", 5},
        {48, "Willian Pacho", 25, "ZAG", 5},
        {49, "Nuno Mendes", 24, "LE", 5},
        {50, "Joao Neves", 21, "VOL", 5},
        {51, "Vitinha", 26, "MC", 5},
        {52, "Desire Doue", 21, "MEI", 5},
        {53, "Khvicha Kvaratskhelia", 25, "PE", 5},
        {54, "Ousmane Dembele", 29, "PD", 5},
        {55, "Goncalo Ramos", 25, "CA", 5},

        // ======================
        // Bayern München
        // ======================

        {56, "Manuel Neuer", 40, "GK", 6},
        {57, "Konrad Laimer", 29, "LD", 6},
        {58, "Dayot Upamecano", 27, "ZAG", 6},
        {59, "Kim Min-jae", 30, "ZAG", 6},
        {60, "Alphonso Davies", 26, "LE", 6},
        {61, "Joshua Kimmich", 32, "VOL", 6},
        {62, "Aleksandar Pavlovic", 22, "MC", 6},
        {63, "Jamal Musiala", 23, "MEI", 6},
        {64, "Michael Olise", 24, "PD", 6},
        {65, "Kingsley Coman", 30, "PE", 6},
        {66, "Harry Kane", 33, "CA", 6},

        // ======================
        // Arsenal
        // ======================

        {67, "David Raya", 31, "GK", 7},
        {68, "Ben White", 29, "LD", 7},
        {69, "William Saliba", 25, "ZAG", 7},
        {70, "Gabriel Magalhaes", 28, "ZAG", 7},
        {71, "Riccardo Calafiori", 24, "LE", 7},
        {72, "Martin Zubimendi", 27, "VOL", 7},
        {73, "Declan Rice", 28, "MC", 7},
        {74, "Martin Odegaard", 28, "MEI", 7},
        {75, "Bukayo Saka", 25, "PD", 7},
        {76, "Gabriel Martinelli", 25, "PE", 7},
        {77, "Viktor Gyokeres", 28, "CA", 7},

        // ======================
        // Manchester City
        // ======================

        {78, "Ederson", 33, "GK", 8},
        {79, "Rico Lewis", 22, "LD", 8},
        {80, "Ruben Dias", 29, "ZAG", 8},
        {81, "Josko Gvardiol", 25, "ZAG", 8},
        {82, "Rayan Ait-Nouri", 25, "LE", 8},
        {83, "Rodri", 30, "VOL", 8},
        {84, "Tijjani Reijnders", 28, "MC", 8},
        {85, "Phil Foden", 26, "MEI", 8},
        {86, "Savinho", 22, "PD", 8},
        {87, "Jeremy Doku", 24, "PE", 8},
        {88, "Erling Haaland", 26, "CA", 8},

        // ======================
        // Manchester United
        // ======================

        {89, "Andre Onana", 30, "GK", 9},
        {90, "Noussair Mazraoui", 28, "LD", 9},
        {91, "Matthijs de Ligt", 26, "ZAG", 9},
        {92, "Lisandro Martinez", 28, "ZAG", 9},
        {93, "Patrick Dorgu", 21, "LE", 9},
        {94, "Manuel Ugarte", 25, "VOL", 9},
        {95, "Bruno Fernandes", 32, "MC", 9},
        {96, "Mason Mount", 28, "MEI", 9},
        {97, "Amad Diallo", 24, "PD", 9},
        {98, "Matheus Cunha", 27, "PE", 9},
        {99, "Rasmus Hojlund", 23, "CA", 9},

        // ======================
        // Chelsea
        // ======================

        {100, "Robert Sanchez", 29, "GK", 10},
        {101, "Reece James", 27, "LD", 10},
        {102, "Levi Colwill", 23, "ZAG", 10},
        {103, "Wesley Fofana", 25, "ZAG", 10},
        {104, "Marc Cucurella", 28, "LE", 10},
        {105, "Moises Caicedo", 25, "VOL", 10},
        {106, "Enzo Fernandez", 25, "MC", 10},
        {107, "Cole Palmer", 24, "MEI", 10},
        {108, "Pedro Neto", 26, "PD", 10},
        {109, "Jamie Gittens", 22, "PE", 10},
        {110, "Joao Pedro", 25, "CA", 10},

        // ======================
        // Juventus
        // ======================

        {111, "Michele Di Gregorio", 29, "GK", 11},
        {112, "Timothy Weah", 26, "LD", 11},
        {113, "Pierre Kalulu", 26, "ZAG", 11},
        {114, "Bremer", 29, "ZAG", 11},
        {115, "Andrea Cambiaso", 26, "LE", 11},
        {116, "Manuel Locatelli", 28, "VOL", 11},
        {117, "Khephren Thuram", 25, "MC", 11},
        {118, "Teun Koopmeiners", 28, "MEI", 11},
        {119, "Francisco Conceicao", 23, "PD", 11},
        {120, "Kenan Yildiz", 21, "PE", 11},
        {121, "Jonathan David", 26, "CA", 11},

        // ======================
        // Roma
        // ======================

        {122, "Mile Svilar", 27, "GK", 12},
        {123, "Zeki Celik", 29, "LD", 12},
        {124, "Gianluca Mancini", 30, "ZAG", 12},
        {125, "Evan Ndicka", 26, "ZAG", 12},
        {126, "Angelino", 29, "LE", 12},
        {127, "Bryan Cristante", 31, "VOL", 12},
        {128, "Manu Kone", 25, "MC", 12},
        {129, "Paulo Dybala", 33, "MEI", 12},
        {130, "Matias Soule", 23, "PD", 12},
        {131, "Lorenzo Pellegrini", 30, "PE", 12},
        {132, "Artem Dovbyk", 29, "CA", 12},
}

const int NUM_TIMES_DEMO = sizeof(TIMES_DEMO) / sizeof(TIMES_DEMO[0]);

void carregarTimesDemo(Time times[], int *totalTimes)
{
    for (int i = 0; i < NUM_TIMES_DEMO; i++)
    {
        times[i] = TIMES_DEMO[i];
    }

    *totalTimes = NUM_TIMES_DEMO;
}

void carregarTimesDemo(Jogador jogadores[], int *totalJogadores)
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
    carregarDadosDemo(times, totalTimes);

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
