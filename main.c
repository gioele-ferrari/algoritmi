#include "header.h"

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
    elimina_occorrenza_all(A, VET_TAPPO, 5);
    stampa_vettore(A, VET_TAPPO);
    return 0;
}

/**
 * @param A vettore da cui ricavare la lunghezza
 * @param n la dimensione del vettore
 * L'algoritmo ha un complessità di O(m) dove m è la dimensione del vettore
 * @return la lunghezza del vettore senza -1
*/
int get_length(int A[], int n) {
    int i = 0;
    while(A[i] != -1) {
        i++;
    }
    return i;
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
        printf("[%d]: %d\n", i, A[i]);
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
 * @param A vettore in cui effettuare l'inserzione.
 * @param n la dimensione del vettore.
 * @param x numero da inserire.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return l'indice del nuovo elemento, -1 se non si può inserire.
*/
int inserisci_coda(int A[], int n, int x) {
    int i = 0;
    i = get_length(A, n);
    
    if(i < n - 1) {
        A[i] = x;
        A[i + 1] = -1;
    }
    else {
        i = -1;
    }
    return i; 
}

/**
 * @param A vettore in cui effettuare l'inserzione.
 * @param n la dimensione del vettore.
 * @param x numero da inserire.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int inserisci_testa(int A[], int n, int x) {
    int i = 0, inserito = 0;
    i = get_length(A, n);

    if(i < n - 1) {
        for(int j = i; j > 0; j--) {
            A[j + 1] = A[j];
        }
        A[0] = x;
        inserito = 1;
    }
    return inserito;
}

/**
 * @param A vettore in cui effettuare l'inserzione.
 * @param n la dimensione del vettore.
 * @param x numero da inserire.
 * @param k indice del numero x.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int inserisci_posizione(int A[], int n, int x, int k) {
    int i = 0, inserito = 0;
    i = get_length(A, n);

    if(k < 0 || k > n || i == n - 1 || k >= i + 1) {
        printf("Impossibile inserire elemento in posizione %d", k);
    }
    else {
        for (int j = i; j >= k; j--) {
            A[j + 1] = A[j]; 
        }
        A[k] = x;
        inserito = 1;
    }
    return inserito;
}

/**
 * @param A vettore in cui effettuare l'inserzione.
 * @param n la dimensione del vettore.
 * @param x occorrenza da trovare.
 * @param newx nuovo numero da inserire.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int inserisci_occorrenza(int A[], int n, int x, int k) {
    int i = 0, j = 0,inserito = 0, trovato = 0;
    if(A[0] == -1) {
        printf("Impossibile inserire elementi, vettore vuoto!\n");
    }
    else {
        while ((A[i] != -1) && (!trovato)) {
            if(A[i] == x) {
                trovato = 1;
            } else {
                i++;
            }
        }

        if(trovato) {    
            j = get_length(A, n);
            for(int l = j; l >= i; l--) {
                A[l + 1] = A[l];
            }
            A[i] = k;
            inserito = i;
        }
    }
    return inserito;
}

/**
 * @param A vettore in cui effettuare l'eliminazione.
 * @param n la dimensione del vettore.
 * @param k posizione da eliminare.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int elimina_posizione(int A[], int n, int k) {
    int i = 0, j = 0, eliminato = 0;
    if(k < 0 || k > (n - 1)) {
        printf("Posizione non valida, riprovare!\n");
    }
    else {
        i = get_length(A, n);
        for(j = k + 1; j <= i; j++) {
            A[j - 1] = A[j];
        }
        eliminato = k;
    }
    return eliminato;
}

/**
 * @param A vettore in cui effettuare l'eliminazione.
 * @param n la dimensione del vettore.
 * @param x occorrenza da eliminare.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return nessun return.
*/
void elimina_occorrenza(int A[], int n, int x) {
    int i = 0, j = 0, len = 0, trovato = 0;

    while ((A[i] != -1) && (!trovato)) {
        if(A[i] == x) {
            trovato = 1;
        }
        else {
            i++;
        }
    }
    len = get_length(A, n);
    for(j = i + 1; j <= len; j++) {
        A[j - 1] = A[j];
    } 
}

/**
 * @param A vettore in cui effettuare l'eliminazione.
 * @param n la dimensione del vettore.
 * @param x occorrenza da eliminare.
 * L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return nessun return.
*/
void elimina_occorrenza_all(int A[], int n, int x) {
    int i = 0, j = 0, len = 0, trovato = 0;
    len = get_length(A, n);
    while (A[i] != -1) {
        if(A[i] == x) {
            for(j = i + 1; j <= len; j++) {
                A[j - 1] = A[j];
            }
            len--;
        }
        else {
            i++;
        }
    }
    
}