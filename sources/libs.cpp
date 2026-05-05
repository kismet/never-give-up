#include "../includes/types.h"
#include "../includes/libs.h"

#include <iostream>
#include <ostream>

bool create(Tempo_t& t, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {
    Tempo_t tempo;
    tempo.ore=o;
    tempo.minuti=m;
    tempo.secondi=s;
    tempo.microsecondi=ms;

    return true;
}

bool before(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1.microsecondi<tempo2.microsecondi) {
        if (tempo1.secondi<tempo2.secondi) {
            if (tempo1.minuti<tempo2.minuti) {
                if (tempo1.ore<tempo2.ore) {
                    return true;
                }
            }
        }
    }
    else {
        return false;
    }
}

bool after(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1.microsecondi>tempo2.microsecondi) {
        if (tempo1.secondi>tempo2.secondi) {
            if (tempo1.minuti>tempo2.minuti) {
                if (tempo1.ore>tempo2.ore) {
                    return true;
                }
            }
        }
    }
    else {
        return false;
    }
}

bool equal(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1.microsecondi==tempo2.microsecondi) {
        if (tempo1.secondi==tempo2.secondi) {
            if (tempo1.minuti==tempo2.minuti) {
                if (tempo1.ore==tempo2.ore) {
                    return true;
                }
            }
        }
    }
    else {
        return false;
    }
}

void add(Tempo_t& tempo1, Tempo_t& tempo2) {
    tempo1.ore=tempo1.ore+tempo2.ore;
    tempo1.minuti=tempo1.minuti+tempo2.minuti;
    tempo1.secondi=tempo1.secondi+tempo2.secondi;
    tempo1.microsecondi=tempo1.microsecondi+tempo2.microsecondi;
}

bool diff(Tempo_t& tempo1, const Tempo_t* tempo2) {
    if (after(tempo1, *tempo2)) {
        tempo1.ore=tempo1.ore-tempo2->ore;
        tempo1.minuti=tempo1.minuti-tempo2->minuti;
        tempo1.secondi=tempo1.secondi-tempo2->secondi;
        tempo1.microsecondi=tempo1.microsecondi-tempo2->microsecondi;

        return true;
    }
    else {
        return false;
    }
}

void print(Tempo_t* tempo) {
    std::cout<<tempo->ore<<":"<<tempo->minuti<<":"<<tempo->secondi<<":"<<tempo->microsecondi<<std::endl;
}