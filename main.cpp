#include <iostream>
#include <string>


using namespace std;

int main() {
    Studente s;

    crea_studente(s,"lenzi","informatica");
    aggiungi_voto(s,3);
    aggiungi_voto(s,4.5);
    aggiungi_voto(s,9);

    calcola_media(&s);

    penalizza(s, 2);

    cout << "Studente: " << s.nome << " Media: " << s.media << endl;
    return 0;
}