#include <stdio.h>
#include <stdlib.h>

#define VET_TAPPO 8

int get_length(int A[], int n);
void stampa_vettore(int A[], int n);
void stampa_maggiore(int A[], int n, int x);
int conta_maggiore(int A[], int n, int x);

int find(int A[], int n, int x);
int find_index(int A[], int n, int x, int k);

void aggiungi_condizione(int A[], int n, int x, int y);

void inserisci_vettore(int A[], int n);
int inserisci_coda(int A[], int n, int x);
int inserisci_testa(int A[], int n, int x);
int inserisci_posizione(int A[], int n, int x, int k);
int inserisci_occorrenza(int A[], int n, int x, int k);

int elimina_posizione(int A[], int n, int k);
void elimina_occorrenza(int A[], int n, int x);
void elimina_occorrenza_all(int A[], int n, int x);

void duplica_vettore(int A[], int n, int B[]);
void duplica_vettore_x(int A[], int n, int x, int B[]);