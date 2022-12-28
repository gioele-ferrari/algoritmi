#include <stdio.h>
#include <stdlib.h>

#define VET_TAPPO 8

void load_vettore(int A[], int n);
void stampa_vettore(int A[], int n);
void stampa_maggiore(int A[], int n, int x);
int count_maggiore(int A[], int n, int x);
int find(int A[], int n, int x);
int find_index(int A[], int n, int x, int k);
void add_condizione(int A[], int n, int x, int y);
int inserisci_coda(int A[], int n, int x);

int main(int argc, char const *argv[])
{
    /**
     * Vettori a tappo
     * Un vettore a tappo è un array delimitato da -1 per esempio
     * A[3] = {1, 2, -1} è un array di elementi con una dimensione
     * che sarà sempre occupabile da 0 a massimo n - 1 dato che 
     * l'elemento all'estremo del vettore è -1. Nel caso ci fossero
     * elementi oltre al delimitatore saranno ignorati.
    */
    int A[VET_TAPPO] = {1, 2, 3, 3, 5, 6, -1};
    int new_index = inserisci_coda(A, VET_TAPPO, 7);
    printf("Nuovo indice: %d\n", new_index);
    stampa_vettore(A, VET_TAPPO);
    return 0;
}

/**
 * @param A vettore da riempire.
 * @param n la dimensione del vettore.
 * L'algoritmo ha un complessità di O(m) dove m è la dimensione del vettore
 * mentre l'invariante è la posizione del vettore da 0 a A[i] (esclusa).
 * @return nessun return.
*/
void load_vettore(int A[], int n) {
    int i = 0, num;
    printf("Inserimento di elementi in un vettore a tappo.\n");
    printf("[%d]: ", i+1);
    scanf("%d", &num);
    A[i] = num;

    while((A[i] != -1) && (i < n - 1)) {
        i++;
        printf("[%d]: ", i+1);
        scanf("%d", &num);
        A[i] = num;
    }

    if(A[i] != -1) {
        printf("Errore, l'ultimo elemento è diverso da -1.\n");
    } else {
        printf("Inserimento avvenuto con successo.\n");
    }
}

/**
 * @param A vettore da stampare.
 * @param n la dimensione del vettore.
 * L'algoritmo ha un complessità di O(min(m, n)) la dimensione è il minore tra
 * il numero di elementi effettivi e la dimensione del vettore (gli elementi possono
 * essere di meno) mentre l'invariante è la posizione del vettore da 0 a A[i] (esclusa).
 * @return nessun return.
*/
void stampa_vettore(int A[], int n) {
    int i = 0;
    printf("Stampa degli elementi in un vettore a tappo.\n");
    
    while ((A[i] != -1)) {
        printf("[%d]: %d\n", i+1, A[i]);
        i++;
    }
}

/**
 * @param A vettore da stampare con una condizione.
 * @param n la dimensione del vettore.
 * @param x numero per la condizione.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è la posizione del vettore da 0 a A[i] (esclusa)
 * che sono più grandi di x.
 * @return nessun return.
*/
void stampa_maggiore(int A[], int n, int x) {
    int i = 0;
    
    printf("Stampa degli elementi in un vettore a tappo maggiori di: %d.\n", x);
    
    while ((A[i] != -1)) {
        if(A[i] > x) {
            printf("[%d]: %d\n", i+1, A[i]);
        }
        i++;
    }
}

/**
 * @param A vettore in cui si contano gli elementi.
 * @param n la dimensione del vettore.
 * @param x numero per la condizione.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è la variabile count che tiene traccia degli elementi
 * più grandi fino alla posizione i - 1.
 * @return numero degli elementi maggiori di x.
*/
int count_maggiore(int A[], int n, int x) {
    int i = 0, count = 0;
    
    printf("Conta degli elementi in un vettore a tappo maggiori di: %d.\n", x);
    
    while ((A[i] != -1)) {
        if(A[i] > x) {
            count++;
        }
        i++;
    }
    return count;
}

/**
 * @param A vettore in cui effettuare la ricerca.
 * @param n la dimensione del vettore.
 * @param x numero da ricercare.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è il vettore da 0 a A[i] (escluso).
 * @return l'indice del numero trovato, -1 se non è presente.
*/
int find(int A[], int n, int x) {
    int i = 0, trovato = 0;
    while ((A[i] != -1) && (trovato == 0)) {
        if(A[i] == x) {
            trovato = 1;
        } 
        else {
            i++;
        }
    }
     
    if(trovato == 1) {
        return i;
    }
    else {
        return -1;
    }
}

/**
 * @param A vettore in cui effettuare la ricerca.
 * @param n la dimensione del vettore.
 * @param x numero da ricercare.
 * @param k numero occorrenza da ricercare.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è count che tiene traccia delle occorrenze tra A e x
 * da posizione O a i - 1.
 * @return l'indice del numero trovato, -1 se non è presente.
*/
int find_index(int A[], int n, int x, int k) {
    int i = 0, trovato = 0, count = 0;
    while ((A[i] != -1) && (trovato == 0) && (i != -1)) {
        i = find(A, n, x);
        if(i != -1) {
            if(count == k) {
                trovato = 1;
            }
            count++;
            i++;
        }
    }
    return i;
}

/**
 * @param A vettore in cui effettuare la modifica.
 * @param n la dimensione del vettore.
 * @param x numero da aggiungere.
 * @param y numero da superare.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è tutti gli elementi del vettore da posizione 0 a posizione
 * A[i] (escluso) maggiori di y sommati a x.
 * @return nessun return.
*/
void add_condizione(int A[], int n, int x, int y) {
    int i = 0;
    while (A[i] != -1) {
        if(A[i] > y) {
            A[i] += x;
        }
        i++;
    }
}

/**
 * @param A vettore in cui effettuare la ricerca.
 * @param n la dimensione del vettore.
 * @param x numero da inserire.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return l'indice del nuovo elemento, -1 se non si può inserire.
*/
int inserisci_coda(int A[], int n, int x) {
    int i = 0;
    while (A[i] != -1) {
        i++;
    }
    
    if(i < n - 1) {
        A[i] = x;
        A[i + 1] = -1;
    }
    else {
        i = -1;
    }
    return i; 
}

