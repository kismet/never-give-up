#include <iostream>

#include "includes/libs.h"
#include "includes/types.h"

using namespace std;
/*
 * QUESTO CODICE E' FATTO PER AIUTARTI A TESTARE LA TUA LIBRERIA
 * MA CONTIENE QUALCHE PICCOLA IMPRECISIONE, CHE DOVRAI CORREGGERE PRIMA DI RIUSCIRE
 * A COMPILARE
 */
int main() {

    cout<<"Questo e' il main che puoi usare per testare la tua libreria"<<endl;
    cout<<"Sentiti libero di aggiungere o corregere il codice in questo file se lo ritieni utile"<<endl;

    Traccia_t alpha;
    Traccia_t beta;
    Traccia_t gamma;

    crea_traccia(alpha, 12,30, 10, 100);
    stampa_info(alpha);
    crea_traccia(beta, 12,130, -1, 100);
    stampa_info(beta);
    crea_traccia(gamma, 1,45, 40, 100);
    stampa_info(gamma);
    cout<<stessa_durata(gamma, alpha);
    cout<<stessa_durata(gamma, gamma);
    cout<<piu_breve(alpha, gamma);
    cout<<piu_lunga(alpha, gamma);

    accoda(gamma, gamma);
    stampa_info(gamma);
    taglia(alpha, &gamma);
    stampa_info(gamma);
    stampa_info(alpha);

return 0;

}