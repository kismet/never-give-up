#include <iostream>

#include "includes/types.h"
//LENZI qui va messa include del .h
#include "includes/libs.h"
//#include "sources/libs.cpp"

using namespace std;
/*
 * QUESTO CODICE E' FATTO PER AIUTARTI A TESTARE LA TUA LIBRERIA
 * MA CONTIENE QUALCHE PICCOLA IMPRECISIONE, CHE DOVRAI CORREGGERE PRIMA DI RIUSCIRE
 * A COMPILARE
 */
int main() {

    cout<<"Questo è il main che puoi usare per testare la tua libreria"<<endl;
    cout<<"Sentiti libero di aggiungere o corregere il codice in questo file se lo ritieni utile"<<endl;

    Tempo_t alpha;
    Tempo_t beta;
    Tempo_t gamma;

    create(alpha, 12,30, 10, 100);
    print(&alpha);
    create(beta, 12,130, -40, 100);
    print(&beta);
    create(gamma, 1,45, 40, 100);
    print(&gamma);
    cout<<equal(gamma, alpha);
    cout<<equal(gamma, gamma);
    cout<<before(alpha, gamma);
    cout<<after(alpha, gamma);

    add(gamma, gamma);
    print(&gamma);
    diff(alpha, &gamma);
    print(&gamma);
    print(&alpha);
}