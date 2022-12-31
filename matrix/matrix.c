#include "matrix.h"

int main(int argc, char const *argv[])
{
    /**
     * Matrici con vettori a tappo
     * Una matrice è un array multidimensionale di n_righe * n_colonne
     * con la quale è possibile svolgere molte funzioni con una complessità
     * più elevata. La dichiarazione di una matrice è sempre nome[righe][colonne]
     * e al suo interno possono essere presente array normali o a tappo.
    */
    int m[MAX][MAX] = {
        {1, 2, 3, -1},
        {4, 0, 6, -1},
        {5, 1, 19, -1},
        {9, 8, 5, -1}
    };
    
    int minX = 0, minY = 0;
    int maxX = 0, maxY = 0;
    massimo_matrice(m, MAX, MAX, &maxX, &maxY);
    printf("MaxX: %d, MaxY: %d\n", maxX, maxY);

    
    minimo_matrice(m, MAX, MAX, &minX, &minY);
    printf("MinX: %d, MinY: %d\n", minX, minY);

    stampa_matrice(m, MAX, MAX);
    return 0;
}

/**
 * @param m vettore matrice da calcolare.
 * @param n la quantità delle righe.
 * L'algoritmo ha un complessità di O(m) dove m è la dimensione della matrice
 * @return lunghezza del vettore.
*/
int get_length(int m[], int n)
{
    int i = 0;
    while(m[i] != -1)
    {
        i++;
    }
    return i;
}

/**
 * @param m matrice da stampare.
 * @param righe la dimensione delle righe.
 * @param colonne la dimensione delle colonne.
 * L'algoritmo ha un complessità di O(m*n) dove m*n è la dimensione della matrice
 * @return nessun return.
*/
void stampa_matrice(int m[MAX][MAX], int righe, int colonne)
{
    int j = 0;
    for (int i = 0; i < righe; i++)
    {
        j = 0;
        while (m[i][j] != -1)
        {
            printf("[%2d]\t", m[i][j]);
            j++;
        }    
        printf("\n");
    }
    printf("\n");
}

/**
 * @param m matrice da stampare.
 * @param righe la dimensione delle righe.
 * @param colonne la dimensione delle colonne.
 * @param coordX puntatore coordinate X.
 * @param coordY puntatore coordinate Y.
 * L'algoritmo ha un complessità di O(m*n) dove m*n è la dimensione della matrice
 * @return nessun return.
 * @attention per passare un puntatore alla funzione usare &.
*/
void minimo_matrice(int m[MAX][MAX], int righe, int colonne, int *coordX, int *coordY)
{
    int valMinimo = m[0][0], j = 0;
    for (int i = 0; i < righe; i++)
    {
        j = 0;
        while (m[i][j] != -1)
        {
            if(m[i][j] < valMinimo)
            {
                valMinimo = m[i][j];
                *coordX = i;
                *coordY = j;
            }
            j++;
        }
    }
}

/**
 * @param m matrice da stampare.
 * @param righe la dimensione delle righe.
 * @param colonne la dimensione delle colonne.
 * @param coordX puntatore coordinate X.
 * @param coordY puntatore coordinate Y.
 * L'algoritmo ha un complessità di O(m*n) dove m*n è la dimensione della matrice
 * @return nessun return.
 * @attention per passare un puntatore alla funzione usare &.
*/
void massimo_matrice(int m[MAX][MAX], int righe, int colonne, int *coordX, int *coordY)
{
    int valMassimo = m[0][0], j = 0;
    for (int i = 0; i < righe; i++)
    {
        j = 0;
        while (m[i][j] != -1)
        {
            if(m[i][j] > valMassimo)
            {
                valMassimo = m[i][j];
                *coordX = i;
                *coordY = j;
            }
            j++;
        }
    }
}