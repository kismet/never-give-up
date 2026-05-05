#include <iostream>
#include "includes/libs.h"

using namespace std;
/*
 * QUESTO CODICE E' FATTO PER AIUTARTI A TESTARE LA TUA LIBRERIA
 * MA CONTIENE QUALCHE PICCOLA IMPRECISIONE, CHE DOVRAI CORREGGERE PRIMA DI RIUSCIRE
 * A COMPILARE
 */
int main() {

    cout<<"Questo e' il main che puoi usare per testare la tua libreria"<<endl;
    cout<<"Sentiti libero di aggiungere o corregere il codice in questo file se lo ritieni utile"<<endl;

    Batteria_t alpha;
    Batteria_t beta;
    Batteria_t gamma;

    // Setup di alpha + stampa
    setup( alpha, 1, 1, 1, 1 );
    stampa_autonomia(&alpha);

    // Setup di beta + stampa
    setup(beta, 2,2, 2, 2 );
    stampa_autonomia(&beta);

    // Setup di beta + stampa
    setup(gamma, 1,45, 40, 100);
    stampa_autonomia(&gamma);

    cout<<stessa_autonomia(gamma, alpha);
    cout<<stessa_autonomia(gamma, gamma);
    cout<<minor_autonomia(alpha, gamma);
    cout<<maggior_autonomia(alpha, gamma);

    ricarica(gamma, gamma);
    stampa_autonomia(&gamma);
    scarica(alpha, &gamma);
    stampa_autonomia(&gamma);
    stampa_autonomia(&alpha);
}