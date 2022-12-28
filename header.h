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
int inserisci_testa(int A[], int n, int x);
int inserisci_posizione_after(int A[], int n, int x, int k);