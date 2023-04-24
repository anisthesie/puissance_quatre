// C-based Four in a Row game by Diogo Correia

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Constantes pour remplir la grille
#define JOUEUR_BLANC 'B'
#define JOUEUR_NOIR 'N'
#define VIDE '.'

// Taille de la grille
#define COLONNES 7
#define LIGNES 6

// Fonction qui dessinera la grille
void dessiner_tableau();

// Lire l'entrée des joueurs et actualiser la grille
void gerer_entree();

// Verifier si on a une position gagnante
char verifier_gagnant();

// Verifier si on a un match nul (la grille est pleine)
bool match_nul();

// La grille du jeu
char grille[COLONNES][LIGNES];

// C'est le tour a quel joueur ? True pour le joueur en noir, False pour le joueur en blanc
bool tour = false;

// Fonction principale
int main() {
    printf("Deux joueurs pouront joueur à tour de role.\n");
    printf("Le joueur blanc commence.\n");

    // Initialiser le tableau
    int i, j;
    for (i = 0; i < COLONNES; i++)
        for (j = 0; j < LIGNES; j++)
            grille[i][j] = VIDE;

    // Boucle de jeu
    // Active tant qu'il n'y a pas de gagnant ou de match nul
    char gagnant = VIDE;
    do {
        dessiner_tableau();
        gerer_entree();
        gagnant = verifier_gagnant();
    } while (gagnant == VIDE && !match_nul());

    // On est sorti de la boucle
    // On a donc un gagnant ou un match nul

    dessiner_tableau();

    if (!match_nul()) {             // Pas de match nul
        if (gagnant == JOUEUR_NOIR)
            printf("Le joueur en noir a gagné!\n");
        else if (gagnant == JOUEUR_BLANC)
            printf("Le joueur en blanc a gagné!\n");

    } else                          // Match nul
        printf("Match nul!\n");


    printf("Appuyer sur Entrer pour quitter\n");
    char ch;
    scanf("%c", &ch);
    scanf("%c", &ch);

    return 0;
}

void dessiner_tableau() {
    int a, b, c;
    for (a = LIGNES - 1; a >= 0; a--) {
        for (b = 0; b < COLONNES; b++) {
            printf("|"  "%c"  "| ", grille[b][a]);
        }
        printf("\n");

    }
    for (c = 0; c < COLONNES; c++)
        printf("____");
    printf("\n");
    for (c = 0; c < COLONNES; c++)
        printf("|%d| ", c + 1);
    printf("\n\n");
}

// Gérer l'entrée des joueurs et jouer un tour.
void gerer_entree() {

    int colonne;

    if (tour)
        printf("\nAu Joueur en noir de jouer, entrer une colonne: ");
    else printf("\nAu Joueur en blanc de jouer, entrer une colonne: ");

    scanf(" %d", &colonne);
    getchar();

    if (colonne < 1 || colonne > COLONNES) {
        printf("Entrée invalide. Réessayez.");
        gerer_entree();
        return;
    }

    int i;
    for (i = 0; i < LIGNES; i++) {
        if (grille[colonne - 1][i] != VIDE)
            continue;
        if (tour)
            grille[colonne - 1][i] = JOUEUR_NOIR;
        else
            grille[colonne - 1][i] = JOUEUR_BLANC;

        tour = !tour;
        return;
    }
    printf("\nPosition invalide. Réessayez.\n");
    gerer_entree();
}

// Verifier s'il y'a une position gagnante.
char verifier_gagnant() {
    int i, j;
    for (i = 0; i < COLONNES; i++)
        for (j = 0; j < LIGNES; j++) {
            if (grille[i][j] == VIDE)
                continue;
            // Verifier verticalement
            if (grille[i][j] == grille[i][j + 1] && grille[i][j] == grille[i][j + 2] &&
                grille[i][j] == grille[i][j + 3])
                return grille[i][j];

            // Verifier horizontalement
            if (grille[i][j] == grille[i + 1][j] && grille[i][j] == grille[i + 2][j] &&
                grille[i][j] == grille[i + 3][j])
                return grille[i][j];

            // Verifier en diagonale et à droite
            if (grille[i][j] == grille[i + 1][j + 1] && grille[i][j] == grille[i + 2][j + 2] &&
                grille[i][j] == grille[i + 3][j + 3])
                return grille[i][j];
            // Verifier en diagonale et à gauche
            if (grille[i][j] == grille[i - 1][j + 1] && grille[i][j] == grille[i - 2][j + 2] &&
                grille[i][j] == grille[i - 3][j + 3])
                return grille[i][j];
        }
}

// Verifier si toutes les cases sont pleines.
bool match_nul() {
    int a, b;
    for (a = 0; a < COLONNES; a++)
        for (b = 0; b < LIGNES; b++)
            if (grille[a][b] == VIDE)
                return false;
    return true;
}
