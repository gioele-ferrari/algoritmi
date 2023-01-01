#include "assert.h"

int main(int argc, char const *argv[])
{
    /**
     * Gli assert hanno una funzione ben precisa nella programmazione:
     * verificare il flusso di codice interrompendolo se questi ultimi
     * non vengono rispettati. Per esempio se nel seguente codice prendessimo
     * l'input dell'utente e per qualche motivo quest'ultimo sia modificato
     * con un valore non valido, possiamo mettere un controllo che interrompe 
     * il programma. Questo è molto utile in fase di progettazione.
    */
    int scelta = 0;
    while (scelta < 1 || scelta > 4)
    {
        printf("Inserisci un valore: ");
        scanf("%d", &scelta);
    }
    
    scelta = 0;
    /**
     * L'assert bloccherà il programma nel caso in cui la condizione non venga
     * rispettata, come un if ma di controllo di debug.
    */
    assert(scelta >= 1 && scelta<= 4); 

    return 0;
}
