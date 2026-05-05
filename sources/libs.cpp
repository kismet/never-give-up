// Autore: (Landucci Gianmarco)
// Data:   (2026/05/05)
// Classe: 3CI
// Fila:    (C)

#include "../includes/types.h"
#include "../includes/libs.h"
using namespace std;

#include <iostream>
#include <ostream>

bool scarto(Cronometro c1, const Cronometro_t *c2) {

    if (&c1 - c2 >= 0) {
        c1 -= c2;
        return true;
    }
    else return false;

}

void mostra(Cronometro_t* c) {

    cout << c->ore << ":" << c->minuti << ":" << c->secondi << ":" << c->microsecondi << endl;

}

bool precede(const Cronometro_t& c1, const Cronometro_t& c2) {

    if (c1.ore > c2.ore) return true;
    return false;
}

void inizializza(Cronometro_t& c, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {

}

bool segue(const Cronometro_t& c1, const Cronometro_t& c2) {

    if (c1.ore > c2.ore) {
        if (c1.minuti > c2.minuti) {
            if (c1.secondi > c2.secondi) {}
        }
    }
}

bool coincide(const Cronometro_t& c1, const Cronometro_t& c2) {

    if (c1.ore == c2.ore && c1.minuti == c2.minuti && c1.secondi == c2.secondi && c1.microsecondi == c2.microsecondi) return true;
    return false;

}

void somma_tempi(Cronometro_t& c1, Cronometro_t& c2) {

    c1.ore += c2.ore;
    c1.minuti += c2.minuti;
    c1.secondi += c2.secondi;
    c1.microsecondi += c2.microsecondi;

}