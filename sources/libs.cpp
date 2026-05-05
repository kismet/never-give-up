// Autore: (Esposito Lorenzo)
// Data:   (2026/05/05)
// Classe: 3CI
// Fila:    (Fila D)

#include "../includes/types.h"
#include "../includes/libs.h"

#include <iostream>
#include <ostream>
using namespace std;

bool minor_autonomia(const Batteria_t& c1, const Batteria_t& c2) {
    if(c1.hours < c2.hours) {
        return true;
    }
    else if(c1.minutes < c2.minutes) {
        return true;
    }
    else if(c1.seconds < c2.seconds) {
        return true;
    }
    else if(c1.microseconds < c2.microseconds) {
        return true;
    }

    return false;
}

void stampa_autonomia(Batteria_t* c) {
    cout << c->hours << ":" << c->minutes << ":" << c->seconds << "." << c->microseconds << endl;
}

bool maggior_autonomia(const Batteria_t& c1, const Batteria_t& c2) {
    if(c1.hours < c2.hours) {
        return false;
    }
    else if(c1.minutes < c2.minutes) {
        return false;
    }
    else if(c1.seconds < c2.seconds) {
        return false;
    }
    else if(c1.microseconds < c2.microseconds) {
        return false;
    }

    return true;
}

void ricarica(Batteria_t& c1, Batteria_t& c2) {
    c1.hours += c2.hours;
    c1.minutes += c2.minutes;
    c1.seconds += c2.seconds;
    c1.microseconds += c2.microseconds;
}

bool scarica(Batteria_t& c1, Batteria_t* c2) {
    Batteria_t copia1;
    copia1.hours = c1.hours;
    copia1.minutes = c1.minutes;
    copia1.seconds = c1.seconds;
    copia1.microseconds = c1.microseconds;

    if(c1.hours-c2->hours < 0) {
        return false;
    }
    else {
        c1.hours -= c2->hours;
    }

    if(c1.minutes-c2->minutes < 0) {
        c1.hours = copia1.hours;
        return false;
    }
    else {
        c1.minutes -= c2->minutes;
    }

    if(c1.seconds-c2->seconds < 0) {
        c1.hours = copia1.hours;
        c1.minutes = copia1.minutes;
        return false;
    }
    else {
        c1.seconds -= c2->seconds;
    }

    if(c1.microseconds-c2->microseconds < 0) {
        c1.hours = copia1.hours;
        c1.minutes = copia1.minutes;
        c1.seconds = copia1.seconds;
        return false;
    }
    else {
        c1.microseconds -= c2->microseconds;
    }
}