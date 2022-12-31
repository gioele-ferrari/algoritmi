#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int get_length(int A[], int n);
void stampa_matrice(int m[MAX][MAX], int righe, int colonne);
void minimo_matrice(int m[MAX][MAX], int righe, int colonne, int *coordX, int *coordY);
void massimo_matrice(int m[MAX][MAX], int righe, int colonne, int *coordX, int *coordY);