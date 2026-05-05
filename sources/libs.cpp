
// Autore: (Mannucci)
// Data:   (2026/05/05)
// Classe: 3CI
// Fila:   D

#include "../includes/types.h"
#include "../includes/libs.h"

#include <iostream>
using namespace std;

// TODO: restituire true o false
bool setup(Batteria_t& c, uint64_t o, uint8_t m, uint8_t s, uint32_t ms) {

    // Ore
    c.hours = o;

    // Minuti
    c.minutes = m;

    // Secondi
    c.seconds = s;

    // Ms
    c.microseconds = ms;

    return true;
}

bool minor_autonomia(const Batteria_t& c1, const Batteria_t& c2) {

    if ( c1.hours < c2.hours ) {
        if ( c1.minutes < c2.minutes ) {
            if ( c1.seconds < c2.seconds ) {
                if ( c1.microseconds < c2.microseconds ) {
                    return true;
                }
            }
        }
    }

    return false;
}