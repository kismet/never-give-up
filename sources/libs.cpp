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
    if ( o<0 || m<0 || s<0 || ms<0 ) {
        return false;
    }
    t.ore = o;
    t.microsecondi = ms;
    t.minuti = m;
    t.secondi = s;
    normalizza(t);
    return true;
}

// True se x viene prima di y
bool before(const Tempo_t& x, const Tempo_t& y) {
    /*
     * Il metodo più semplice è portare tutto in microsecondi e riusando la funzione appena creata
     *
     * uint64_t alpha = time_to_micro(x);
     * uint64_t beta = time_to_micro(y);
     *
     * return alpha<beta;
     */
    if (x.ore < y.ore) {
        return true;
    }else if (x.ore > y.ore) {
        return false;
    }

    //Arrivati a questo punto siamo sicuri che x.ore=y.ore
    if (x.minuti < y.minuti) {
        return true;
    }else if (x.minuti > y.minuti) {
        return false;
    }

    //Arrivati a questo punto siamo sicuri che x.ore=y.ore e x x.minuti == y.minuti
    if (x.secondi < y.secondi) {
        return true;
    }else if (x.secondi > y.secondi) {
        return false;
    }

    //Arrivati a questo punto siamo sicuri che x.ore=y.ore, x.minuti == y.minuti e x.secondi == y.secondi
    return x.microsecondi < y.microsecondi;
}

// True se tempo1 viene dopo tempo2
bool after(const Tempo_t& a, const Tempo_t& b) {
    /*
     * Il metodo più semplice è portare tutto in microsecondi e riusando la funzione appena creata
     *
     * uint64_t alpha = time_to_micro(a);
     * uint64_t beta = time_to_micro(b);
     *
     * return alpha>beta;
     */
    return before(b,a)==false && equal(a,b) == false;
}

// True se e solo se U e V sono uguali
bool equal(const Tempo_t& u, const Tempo_t& v) {
    /*
     * Il metodo più semplice è portare tutto in microsecondi e riusando la funzione appena creata
     *
     * uint64_t alpha = time_to_micro(u);
     * uint64_t beta = time_to_micro(v);
     *
     * return alpha==beta;
     */
    if (u.ore != v.ore) {
        return false;
    }
    if (u.minuti != v.minuti) {
        return false;
    }
    if (u.secondi != v.secondi) {
        return false;
    }
    if (u.microsecondi != v.microsecondi) {
        return false;
    }
    return true;
}

// Somma i due tempi ed il risultato va in tempo1
void add(Tempo_t& x, Tempo_t& y) {
    x.ore += y.ore;
    x.minuti += y.minuti;
    x.secondi += y.secondi;
    x.microsecondi += y.microsecondi;
    normalizza(x);
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
bool diff(Tempo_t& x, const Tempo_t* y) {
    if (before(x,*y)) return false;
    uint64_t alpha = time_to_micro(&x);
    uint64_t beta = time_to_micro(y);
    alpha -= beta;
    micro_to_time(x, alpha );
    return true;
}

using namespace  std;
// Stampa un tempo in modo formattato HHH:MM:SS.MS
void print( Tempo_t* t) {
    cout<<t->ore<<":"<<(uint32_t)t->minuti<<":"<<(uint32_t)t->secondi<<"."<<t->microsecondi<<endl;
}