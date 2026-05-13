#include "../includes/libs.h"

#include <iostream>
#include <ratio>

bool create(Tempo_t& t, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {
    t.ore = o;
    t.minuti  = m;
    t.secondi = s;
    t.microsecondi = ms;

    int millisecondi;

    //LENZI Servono 1000 microsecondi per fare un secondo
    while (t.microsecondi > 100) {
        t.microsecondi = t.microsecondi - 100;
        millisecondi++;
        ms = t.microsecondi;
    }
    while (millisecondi > 100) {
        millisecondi = millisecondi - 100;
        t.secondi++;
    }
    //LENZI bastava fare secondi+=microsecondi/(1000*1000) e microsecondi=microsecondi%(1000*1000)
    while (t.secondi > 60) {
        t.secondi = t.secondi - 60;
        t.minuti++;
        s = t.secondi;
    }
    while (t.minuti > 60) {
        t.minuti = t.minuti - 60;
        t.ore++;
        m = t.minuti;
    }
    if (t.ore != o) {
        //LENZI perchè?
        return false;
    }
    if (t.minuti != m) {
        //LENZI perchè?
        return false;
    }
    if (t.secondi != s) {
        //LENZI perchè?
        return false;
    }
    if (t.microsecondi != s) {
        //LENZI perchè?
        return false;
    }
    //LENZI manca return true
}

// True se tempo1 viene prima di tempo2
bool before(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1.ore < tempo2.ore) {
        return true;
    }
    //LENZI dovevi mettere questo
    /*
    else if ( tempo1.ore > tempo2.ore ){
        return false;
    }
    */
    //LENZI logica sbagliata in questo caso non è deto che tempo1.ore < tempo2.ore
    if (tempo1.minuti < tempo2.minuti) {
        return true;
    }
    if (tempo1.secondi < tempo2.secondi) {
        return true;
    }
    if (tempo1.microsecondi < tempo2.secondi) {
        return true;
    }
    return false;
}

// True se tempo1 viene dopo tempo2
bool after(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    //LENZI sbagliata la logica, possono essere uguali se non è dopo!
     return !before(tempo1, tempo2);
}

// True se e solo se tempo1 e tempo2 sono uguali
bool equal(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1.ore == tempo2.ore) {
        //LENZI sbagliata la logica, se sono diversi è falso, ma altrimenti devo vedere anche il resto delle unita
        return true;
    }
    if (tempo1.minuti == tempo2.minuti) {
        return true;
    }
    if (tempo1.secondi == tempo2.secondi) {
        return true;
    }
    if (tempo1.microsecondi == tempo2.secondi) {
        return true;
    }
    return false;
}

// Somma i due tempi ed il risultato va in tempo1
void add(Tempo_t& tempo1, Tempo_t& tempo2) {
    //LENZI devi verificare che ore minuti e secondi siano tra 0 e 60 e fare il riporto
    tempo1.ore = tempo1.ore + tempo2.ore;
    tempo1.minuti = tempo1.minuti + tempo2.minuti;
    tempo1.secondi = tempo1.secondi + tempo2.secondi;
    tempo1.microsecondi = tempo1.microsecondi + tempo2.microsecondi;
}

bool diff(Tempo_t& tempo1, const Tempo_t* tempo2) {
    Tempo_t temp;
    temp.ore = tempo1.ore - tempo2->ore;
    temp.minuti = tempo1.minuti - tempo2->minuti;
    temp.secondi = tempo1.secondi - tempo2->secondi;
    temp.microsecondi = tempo1.microsecondi - tempo2->microsecondi;
    if (temp.ore > 0) {
        //LENZI sbagliata la logica se minore di zero puoi dire false ed uscire
        return true;
    }
    if (temp.minuti > 0) {
        return true;
    }
    if (temp.secondi > 0) {
        return true;
    }
    if (temp.microsecondi > 0) {
        return true;
    }
    //LENZI qui doveva essere vero e dovevi assegnare tempo1 = temp;
    return false;
}

// Stampa un tempo in modo formattato HHH:MM:SS.MS
void print( Tempo_t* tempo) {
    int ore = tempo->ore;
    int minuti = tempo->minuti;
    int secondi = tempo->secondi;
    int microsecondi = tempo->microsecondi;
    std::cout << ore << ":" << minuti << ":" << secondi << "." << microsecondi << '\n';
}