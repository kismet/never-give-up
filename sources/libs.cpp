
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
    if ( ( o >= 0 ) && ( 0 < 24 ) ) {
        c.hours = o;

        // Minuti
        if ( ( m >= 0 ) && ( m <= 60 ) ) {
            c.minutes = m;

            // Secondi
            if ( ( s >= 0 ) && ( s <= 60 ) ) {
                c.seconds = s;

                // Ms
                if ( ( ms >= 0 ) && ( ms <= 60 ) ) {
                    c.microseconds = ms;

                    return true;
                }
            }
        }
    }

    return false;
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

void stampa_autonomia(Batteria_t* c) {

    cout << c->hours << ":" << c->minutes << ":" << c->seconds << ":" << c->microseconds << endl;
}

bool maggior_autonomia(const Batteria_t& c1, const Batteria_t& c2) {

    if ( c1.hours > c2.hours ) {
        if ( c1.minutes > c2.minutes ) {
            if ( c1.seconds > c2.seconds ) {
                if ( c1.microseconds > c2.microseconds ) {
                    return true;
                }
            }
        }
    }

    return false;

}

void ricarica(Batteria_t& c1, Batteria_t& c2) {

    c1.hours += c2.hours;
    c1.minutes += c2.minutes;
    c1.seconds += c2.seconds;
    c1.microseconds += c2.microseconds;

}

bool scarica( Batteria_t& c1, const Batteria_t* c2) {

    if ( ( c1.hours - c2->hours ) > 0 ) {
        c1.hours -= c2->hours;

        if ( ( c1.minutes - c2->minutes ) > 0 ) {
            c1.minutes -= c2->minutes;

            if ( ( c1.seconds - c2->seconds ) > 0 ) {
                c1.seconds -= c2->seconds;

                if ( ( c1.microseconds - c2->microseconds ) > 0 ) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool stessa_autonomia(const Batteria_t& c1, const Batteria_t& c2) {

    if ( c1.hours == c2.hours ) {
        if ( c1.minutes == c2.minutes ) {
            if ( c1.seconds == c2.seconds ) {
                if ( c1.microseconds == c2.microseconds ) {
                    return true;
                }
            }
        }
    }

    return false;
}