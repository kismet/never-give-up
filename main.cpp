#include <iostream>
#include "includes/types.h"
#include "includes/libs.h"

using namespace std;

int main() {

    cout<<"Questo e' il main che puoi usare per testare la tua libreria"<<endl;
    cout<<"Sentiti libero di aggiungere o corregere il codice in questo file se lo ritieni utile"<<endl;

    Traccia_t alpha;
    Traccia_t beta;
    Traccia_t gamma;

    crea_traccia(alpha, 12,30, 10, 100);
    stampa_info(&alpha);
    crea_traccia(beta, 12,130, -40, 100);
    stampa_info(&beta);
    crea_traccia(gamma, 1,45, 40, 100);
    stampa_info(&gamma);
    cout<<stessa_durata(gamma, alpha)<< endl;
    cout<<stessa_durata(gamma, gamma)<< endl;
    cout<<piu_breve(alpha, gamma)<< endl;
    cout<<piu_lunga(alpha, gamma)<< endl;

    accoda(gamma, gamma);
    stampa_info(&gamma);
    taglia(alpha, &gamma);
    stampa_info(&gamma);
    stampa_info(&alpha);

return 0;

}
