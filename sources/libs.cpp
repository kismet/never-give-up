#include "../includes/types.h"
#include "../includes/libs.h"
#include <iostream>

void normalizza(Tempo_t& tempo) {
    uint16_t tmp;
    if (tempo.microsecondi > 1'000'000) {
        tmp = tempo.microsecondi / 1'000'000;
        tempo.microsecondi = tempo.microsecondi % 1'000'000;
        tempo.secondi += tmp;
    }
    if (tempo.secondi > 60) {
        tmp = tempo.secondi / 60;
        tempo.secondi = tempo.secondi % 60;
        tempo.minuti += tmp;
    }
    if (tempo.minuti > 60) {
        tmp = tempo.minuti / 60;
        tempo.minuti = tempo.minuti % 60;
        tempo.ore += tmp;
    }
}

// Inizializzazione comoda della struct se l'inizializzazione non è possibile restituisce false
bool create(Tempo_t& t, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {

};

// True se tempo1 viene prima di tempo2
bool before(const Tempo_t& tempo1, const Tempo_t& tempo2) {

    if (tempo1 < tempo2) {
        return true;
    }

};

// True se tempo1 viene dopo tempo2
bool after(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1 > tempo2) {
        return true;
    }
};

// True se e solo se tempo1 e tempo2 sono uguali
bool equal(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1 == tempo2) {
        return true;
    }
};

// Somma i due tempi ed il risultato va in tempo1
void add(Tempo_t& tempo1, Tempo_t& tempo2) {
    tempo1 = tempo1 + tempo2;
};

uint64_t time_to_micro(const Tempo_t* t) {
    uint64_t tempo = 0;
    tempo += t->ore*60LL*60LL*1'000'000LL;
    tempo += t->minuti*60*1'000'000;
    tempo += t->secondi*1'000'000;
    return tempo;
}

void  micro_to_time(Tempo_t& t, uint64_t ms) {
    t.ore = ms / (60LL*60LL*1'000'000LL);
    ms = ms % (60LL*60LL*1'000'000LL);
    t.minuti = ms / (60*1'000'000);
    ms = ms % (60*1'000'000);
    t.secondi = ms / 1'000'000;
    t.microsecondi = ms % 1'000'000;
}


// Sottrae tempo2 da tempo1 se possibile e restituisce true altrimenti restituisce false non effettua la sottrazione
// il tempo non può mai essere negativo
bool diff(Tempo_t& tempo1, const Tempo_t* tempo2) {

};

// Stampa un tempo in modo formattato HHH:MM:SS.MS
void print( Tempo_t* tempo) {

};