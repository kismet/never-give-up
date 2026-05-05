#include "../includes/types.h"
#include "../includes/libs.h"

// Autore: (Turini Elia)
// Data:   (2026/05/05)
// Classe: 3CI
// Fila:    (FILA:D)

#include <iostream>
using namespace std;

bool setup(Batteria_t& c, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {
    bool inizializzazioneCorretta = true;

    c.hours = o;
    if (c.hours == NULL) {
        inizializzazioneCorretta = false;
    }
    c.minutes = m;
    if (c.minutes == NULL) {
        inizializzazioneCorretta = false;
    }
    c.seconds = s;
    if (c.seconds == NULL) {
        inizializzazioneCorretta = false;
    }
    c.microseconds = ms;
    if (c.microseconds == NULL) {
        inizializzazioneCorretta = false;
    }

    return inizializzazioneCorretta;
}

bool minor_autonomia(const Batteria_t &c1, const Batteria_t &c2) {
    bool autonomia = true;

    double tempoC1;
    double tempoC2;

    tempoC1 = tempoC1 + (c1.hours * 60 * 60);
    tempoC1 = tempoC1 + (c1.minutes * 60);
    tempoC1 = tempoC1 + c1.seconds;
    tempoC1 = tempoC1 + (c1.microseconds / 1000000);

    tempoC2 = tempoC2 + (c2.hours * 60 * 60);
    tempoC2 = tempoC2 + (c2.minutes * 60);
    tempoC2 = tempoC2 + c2.seconds;
    tempoC2 = tempoC2 + (c2.microseconds / 1000000);

    if (tempoC1 >= tempoC2) {
        autonomia = false;
    }

    return autonomia;
}

void stampa_autonomia(Batteria_t* c) {

    cout<<c->hours<<":";
    cout<<c->minutes<<":";
    cout<<c->seconds<<".";
    cout<<c->microseconds<<endl;
}

void ricarica(Batteria_t& c1, Batteria_t& c2) {
    c1.microseconds += c2.microseconds;

    c1.seconds += c2.seconds;
    if (c1.seconds >= 60) {
        c1.seconds -= 60;
        c1.minutes++;
    }

    c1.minutes += c2.minutes;
    if (c1.minutes >= 60) {
        c1.minutes -= 60;
        c1.hours++;
    }

    c1.hours += c2.hours;

}