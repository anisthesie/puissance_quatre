// C-based Four in a Row game by Diogo Correia
/*
// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define constants
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define JOUEUR_A 'A'
#define JOUEUR_B 'B'
#define VIDE '.'


#define COLONNES 7
#define LIGNES 6

// Function declaration
void bienvenue();
void initialiser_tableau();
void dessiner_tableau();
void lancer_jeu();
void execute_play();
char verifier_gagnant();
//char getMatrixAt();
bool match_nul();
void fin_jeu(char winner);

// Board array and starting function
// The first dimension holds columns from left to right
// The second dimension holds rows from bottom to top
// For example, matrix[4][0] means fifth column, bottom row.
char grille[COLONNES][LIGNES];

// This boolean defines which player is playing.
// False means Player 1 (X)
// True means Player 2 (O)
bool tour = false;

// The main function. This is what handles the game start.
int mainn()
{
    bienvenue();
    initialiser_tableau();
    lancer_jeu();
    return 0;
}

// Prints the instructions to the console.
void bienvenue() {
    printf("Vous jouez en blanc. \n");
}

// Initializes an empty board.
void initialiser_tableau()
{
    int i, j;
    for (i = 0; i < COLONNES; i++)
        for (j = 0; j < LIGNES; j++)
            grille[i][j] = VIDE;
}

// Prints the current board to the console.
void dessiner_tableau()
{
    int k, l, m;
    for (k = LIGNES - 1; k >= 0; k--)
    {
        for (l = 0; l < COLONNES; l++)
        {
            switch (grille[l][k])
            {
                case JOUEUR_A:
                    printf(" " ANSI_COLOR_RED "%c" ANSI_COLOR_RESET " ", grille[l][k]);
                    break;
                case JOUEUR_B:
                    printf(" " ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET " ", grille[l][k]);
                    break;
                default:
                    printf(" " ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET " ", grille[l][k]);
            }
        }
        printf("\n");
    }
    for (m = 0; m < COLONNES; m++)
        printf("---");
    printf("\n");
    for (m = 0; m < COLONNES; m++)
        printf(" %d ", m + 1);
    printf("\n\n");
}


// Handles the game logic.
void lancer_jeu()
{
    char winner = VIDE;
    // Keep the game running while no one wins and there is no tie.
    do
    {
        dessiner_tableau();
        execute_play();
        winner = verifier_gagnant();
    } while (winner == VIDE && !match_nul());
    dessiner_tableau();
    fin_jeu(winner);
}

// Executes a round on the game.
void execute_play()
{
    int column;
    printf("\nPlayer %d (%c) turn: ", tour ? 2 : 1, tour ? JOUEUR_B : JOUEUR_A);
    scanf("%d", &column);
    if (column > COLONNES)
    {
        printf("\nInvalid play! There is no such column!\n");
        execute_play();
        return;
    }
    int i;
    for (i = 0; i < LIGNES; i++)
    {
        if (grille[column - 1][i] != VIDE)
            continue;
        grille[column - 1][i] = tour ? JOUEUR_B : JOUEUR_A;
        tour = !tour;
        return;
    }
    printf("\nInvalid play! That column is already full!\n");
    execute_play();
}

// Checks if there is a winner. Does not check ties.
char verifier_gagnant()
{
    int i, j;
    for (i = 0; i < COLONNES; i++)
        // Same here
        for (j = 0; j < LIGNES; j++)
        {
            if (grille[i][j] == VIDE)
                continue;
            // Check vertically only upwards
            if (grille[i][j] == grille[i][j + 1] && grille[i][j] == grille[i][j + 2] && grille[i][j] == grille[i][j + 3])
                return grille[i][j];
            // Check horizontally only to the right
            if (grille[i][j] == grille[i + 1][j] && grille[i][j] == grille[i + 2][j] && grille[i][j] == grille[i + 3][j])
                return grille[i][j];
            // Check diagonally to the right
            if (grille[i][j] == grille[i + 1][j + 1] && grille[i][j] == grille[i + 2][j + 2] && grille[i][j] == grille[i + 3][j + 3])
                return grille[i][j];
            // Check diagonally to the left
            if (grille[i][j] == grille[i - 1][j + 1] && grille[i][j] == grille[i - 2][j + 2] && grille[i][j] == grille[i - 3][j + 3])
                return grille[i][j];
        }

    return VIDE;
}

// Checks if there is a tie.
bool match_nul()
{
    int p, q;
    for (p = 0; p < COLONNES; p++)
        for (q = 0; q < LIGNES; q++)
            if (grille[p][q] == VIDE)
                return false;
    return true;
}

// Ends the game.
void fin_jeu(char winner)
{
    switch (winner)
    {
        case JOUEUR_A:
            printf("\nPlayer 1 won!\n");
            break;
        case JOUEUR_B:
            printf("\nPlayer 2 won!\n");
            break;
        default:
            printf("\nIt's a tie!\n");
    }
    printf("Press ENTER to exit.\n");
    // This waits for an ENTER press;
    char ch;
    scanf("%c", &ch);
    scanf("%c", &ch);
}
*/