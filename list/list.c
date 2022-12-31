#include "list.h"

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
    int A[VET_TAPPO] = {1, 1, 1, 3, 5, 6, -1};
    int B[VET_TAPPO] = {1, 2, 3, 3, 3, 6, -1};

    int num = inserisci_coda(A, VET_TAPPO, 9);
    printf("%d\n", num);
    stampa_vettore(A, VET_TAPPO);
    return 0;
}

/**
 * @param A vettore da cui ricavare la lunghezza
 * @param n la dimensione del vettore.
 * @note L'algoritmo ha un complessità di O(m) dove m è la dimensione del vettore
 * @return la lunghezza del vettore senza -1
*/
int get_length(int A[], int n) 
{
    int i = 0;
    while(A[i] != -1) {
        i++;
    }
    return i;
}

/**
 * @param A vettore da riempire.
 * @param n la dimensione del vettore.
 * @note L'algoritmo ha un complessità di O(m) dove m è la dimensione del vettore
 * mentre l'invariante è la posizione del vettore da 0 a A[i] (esclusa).
 * @return nessun return.
*/
void inserisci_vettore(int A[], int n) 
{
    int i = 0, num;
    printf("Inserimento di elementi in un vettore a tappo.\n");
    printf("[%d]: ", i+1);
    scanf("%d", &num);
    A[i] = num;

    while((A[i] != -1) && (i < n - 1)) 
    {
        i++;
        printf("[%d]: ", i+1);
        scanf("%d", &num);
        A[i] = num;
    }

    if(A[i] != -1) 
    {
        printf("Errore, l'ultimo elemento è diverso da -1.\n");
    } else 
    {
        printf("Inserimento avvenuto con successo.\n");
    }
}

/**
 * @param A vettore da stampare.
 * @param n la dimensione del vettore.
 * @note L'algoritmo ha un complessità di O(min(m, n)) la dimensione è il minore tra
 * il numero di elementi effettivi e la dimensione del vettore (gli elementi possono
 * essere di meno) mentre l'invariante è la posizione del vettore da 0 a A[i] (esclusa).
 * @return nessun return.
*/
void stampa_vettore(int A[], int n) 
{
    int i = 0;
    printf("Stampa degli elementi in un vettore a tappo.\n");
    
    while ((A[i] != -1)) 
    {
        printf("[%d]: %d\n", i, A[i]);
        i++;
    }
}

/**
 * @param A vettore da stampare con una condizione.
 * @param n la dimensione del vettore.
 * @param x numero per la condizione.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è la posizione del vettore da 0 a A[i] (esclusa)
 * che sono più grandi di x.
 * @return nessun return.
*/
void stampa_maggiore(int A[], int n, int x) 
{
    int i = 0;
    
    printf("Stampa degli elementi in un vettore a tappo maggiori di: %d.\n", x);
    
    while ((A[i] != -1)) 
    {
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
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è la variabile conta che tiene traccia degli elementi
 * più grandi fino alla posizione i - 1.
 * @return numero degli elementi maggiori di x.
*/
int conta_maggiore(int A[], int n, int x) 
{
    int i = 0, conta = 0;
    
    printf("Conta degli elementi in un vettore a tappo maggiori di: %d.\n", x);
    
    while ((A[i] != -1)) 
    {
        if(A[i] > x) 
        {
            conta++;
        }
        i++;
    }
    return conta;
}

/**
 * @param A vettore in cui effettuare la ricerca.
 * @param n la dimensione del vettore.
 * @param x numero da ricercare.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è il vettore da 0 a A[i] (escluso).
 * @return l'indice del numero trovato, -1 se non è presente.
*/
int find(int A[], int n, int x) 
{
    int i = 0, trovato = 0;
    while ((A[i] != -1) && (trovato == 0)) 
    {
        if(A[i] == x) 
        {
            trovato = 1;
        } 
        else 
        {
            i++;
        }
    }
     
    if(trovato == 1) 
    {
        return i;
    }
    else 
    {
        return -1;
    }
}

/**
 * @param A vettore in cui effettuare la ricerca.
 * @param n la dimensione del vettore.
 * @param x numero da ricercare.
 * @param k numero occorrenza da ricercare.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è conta che tiene traccia delle occorrenze tra A e x
 * da posizione O a i - 1.
 * @return l'indice del numero trovato, -1 se non è presente.
*/
int find_index(int A[], int n, int x, int k) 
{
    int i = 0, trovato = 0, occorrenza = 0;
    while ((A[i] != -1) && (trovato == 0) && (find(A, n, x) != -1)) 
    {
        if(find(A, n, x) != -1) 
        {
            if(A[i] == x && occorrenza == k - 1)
            {
                trovato = 1;
            }
            else {
                if(A[i] == x && occorrenza < k) {
                    occorrenza++;
                }
                i++;
            }
        }
    }

    if(find(A, n, x) == -1) {
        i = -1;
    }

    return i;
}

/**
 * @param A vettore in cui effettuare la modifica.
 * @param n la dimensione del vettore.
 * @param x numero da aggiungere.
 * @param y numero da superare.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è tutti gli elementi del vettore da posizione 0 a posizione
 * A[i] (escluso) maggiori di y sommati a x.
 * @return nessun return.
*/
void aggiungi_condizione(int A[], int n, int x, int y) 
{
    int i = 0;
    while (A[i] != -1) 
    {
        if(A[i] > y) 
        {
            A[i] += x;
        }
        i++;
    }
}

/**
 * @param A vettore in cui effettuare l'inserzione.
 * @param n la dimensione del vettore.
 * @param x numero da inserire.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return l'indice del nuovo elemento, -1 se non si può inserire.
*/
int inserisci_coda(int A[], int n, int x) 
{
    int i = 0;
    i = get_length(A, n);
    
    if(i < n - 1) 
    {
        A[i] = x;
        A[i + 1] = -1;
    }
    else 
    {
        i = -1;
    }
    return i; 
}

/**
 * @param A vettore in cui effettuare l'inserzione.
 * @param n la dimensione del vettore.
 * @param x numero da inserire.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int inserisci_testa(int A[], int n, int x) 
{
    int i = 0, inserito = 0;
    i = get_length(A, n);

    if(i < n - 1) 
    {
        for(int j = i; j > 0; j--) 
        {
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
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int inserisci_posizione(int A[], int n, int x, int k) 
{
    int i = 0, inserito = 0;
    i = get_length(A, n);

    if(k < 0 || k > n || i == n - 1 || k >= i + 1) 
    {
        printf("Impossibile inserire elemento in posizione %d", k);
    }
    else 
    {
        for (int j = i; j >= k; j--) 
        {
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
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int inserisci_occorrenza(int A[], int n, int x, int k) 
{
    int i = 0, j = 0,inserito = 0, trovato = 0;
    if(A[0] == -1) 
    {
        printf("Impossibile inserire elementi, vettore vuoto!\n");
    }
    else {
        while ((A[i] != -1) && (!trovato)) 
        {
            if(A[i] == x) 
            {
                trovato = 1;
            } else 
            {
                i++;
            }
        }

        if(trovato) 
        {    
            j = get_length(A, n);
            for(int l = j; l >= i; l--) 
            {
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
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return 1 se è andato tutto a buon fine, altrimenti 0.
*/
int elimina_posizione(int A[], int n, int k) 
{
    int i = 0, j = 0, eliminato = 0;
    if(k < 0 || k > (n - 1)) 
    {
        printf("Posizione non valida, riprovare!\n");
    }
    else {
        i = get_length(A, n);
        for(j = k + 1; j <= i; j++) 
        {
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
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return nessun return.
*/
void elimina_occorrenza(int A[], int n, int x) 
{
    int i = 0, j = 0, len = 0, trovato = 0;

    while ((A[i] != -1) && (!trovato)) 
    {
        if(A[i] == x) 
        {
            trovato = 1;
        }
        else 
        {
            i++;
        }
    }
    len = get_length(A, n);
    for(j = i + 1; j <= len; j++) 
    {
        A[j - 1] = A[j];
    } 
}

/**
 * @param A vettore in cui effettuare l'eliminazione.
 * @param n la dimensione del vettore.
 * @param x occorrenza da eliminare.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi.
 * @attention inserire invariante.
 * @return nessun return.
*/
void elimina_occorrenza_all(int A[], int n, int x) 
{
    int i = 0, j = 0, len = 0;
    len = get_length(A, n);
    while (A[i] != -1) 
    {
        if(A[i] == x) 
        {
            for(j = i + 1; j <= len; j++) 
            {
                A[j - 1] = A[j];
            }
            len--;
        }
        else 
        {
            i++;
        }
    }
    
}

/**
 * @param A vettore da duplicare.
 * @param n la dimensione del vettore.
 * @param B vettore risultato.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è il vettore B con gli elementi copiati dalla 
 * posizione 0 alla posizione i - 1.
 * @return nessun return.
*/
void duplica_vettore(int A[], int n, int B[]) 
{
    int i = 0;
    while (A[i] != -1) 
    {
        B[i] = A[i];
        i++;
    }
    B[i] = -1;
}

/**
 * @param A vettore da duplicare.
 * @param n la dimensione del vettore.
 * @param x numero per la condizione.
 * @param B vettore risultato.
 * @note L'algoritmo ha un complessità di O(m) dove m è il numero di elementi
 * mentre l'invariante è il vettore B con gli elementi copiati dalla 
 * posizione 0 alla posizione i - 1 maggiori di x.
 * @return nessun return.
*/
void duplica_vettore_x(int A[], int n, int x, int B[]) 
{
    int i = 0, j = 0;
    while (A[i] != -1) 
    {
        if(A[i] > x)
        {
            B[j] = A[i];
            j++;
        }
        i++;
    }
    B[j] = -1;
}

/**
 * @param A vettore da controllare.
 * @param B vettore da controllare.
 * @param n la dimensione del vettore.
 * @note L'algoritmo ha un complessità di O(min(A, B)) dove m è il numero di elementi minimo
 * tra i due vettori nel caso peggiore si arriva alla dimensione massima
 * @attention inserire invariante.
 * @return 0 se sono diversi, 1 se sono uguali.
*/
int vettori_equivalenti(int A[], int B[], int n) 
{
    int i = 0, uguali = 1;
    while (A[i] != -1 && B[i] != -1 && uguali)
    {
        if(A[i] != B[i]) 
        {
            uguali = 0;
        }
        i++;
    }
    return uguali;
}

/**
 * @param A vettore da controllare.
 * @param B vettore da controllare.
 * @param n la dimensione del vettore.
 * @param x numero nel caso finiscano gli elementi di confronto.
 * @note L'algoritmo ha un complessità di O(max(A, B)) dove m è il numero di elementi minimo
 * tra i due vettori nel caso peggiore si arriva alla dimensione massima
 * @attention inserire invariante.
 * @return 0 se sono diversi, 1 se sono uguali.
*/
int vettori_maggiore(int A[], int B[], int n, int x) 
{
    int i = 0, j = 0, conta = 0;
    while (A[i] != -1 && B[j] != -1)
    {
        if(A[i] > B[j]) 
        {
            conta++;
        }
        i++;
        j++;
    }

    while (A[i] != -1) 
    {
        if(A[i] > x) 
        {
            conta++;
        }
        i++;
    }
    
    while (B[j] != -1) 
    {
        if(x > B[j]) 
        {
            conta++;
        }
        j++;
    }
    return conta;
}


