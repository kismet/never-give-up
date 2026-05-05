#include <iostream>

#include "includes/libs.h"
#include "includes/types.h"

// Autore: (Calcagni Luca)
// Data:   (2026/05/05)
// Classe: 3CI
// Fila:    (C)

using namespace std;
/*
 * QUESTO CODICE E' FATTO PER AIUTARTI A TESTARE LA TUA LIBRERIA
 * MA CONTIENE QUALCHE PICCOLA IMPRECISIONE, CHE DOVRAI CORREGGERE PRIMA DI RIUSCIRE
 * A COMPILARE
 */
int main() {

    cout<<"Questo e' il main che puoi usare per testare la tua libreria"<<endl;
    cout<<"Sentiti libero di aggiungere o corregere il codice in questo file se lo ritieni utile"<<endl;

    Cronometro_t alpha;
    Cronometro_t beta;
    Cronometro_t gamma;

    inizializza(alpha, 12,30, 10, 100);
    mostra(alpha);
    inizializza(beta, 12,130, -40, 100);
    mostra(beta);
    inizializza(gamma, 1,45, 40, 100);
    mostra(gamma);
    cout<<coincide(gamma, alpha);
    cout<<coincide(gamma, gamma);
    cout<<precede(alpha, gamma);
    cout<<segue(alpha, gamma);

    somma_tempi(gamma, gamma);
    mostra(gamma);
    scarto(alpha, gamma);
    mostra(gamma);
    mostra(alpha);
}