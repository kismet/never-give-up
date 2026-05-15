#include "../includes/types.h"
#include "../includes/libs.h"
#include <iostream>
using namespace std;

uint64_t time_to_micro(const Traccia_t* t) {
    uint64_t tempo = 0;
    tempo += t->ore*60LL*60LL*1'000'000LL;
    tempo += t->minuti*60*1'000'000;
    tempo += t->secondi*1'000'000;
    return tempo;
}

void  micro_to_time(Traccia_t& t, uint64_t ms) {
    t.ore = ms / (60LL*60LL*1'000'000LL);
    ms = ms % (60LL*60LL*1'000'000LL);
    t.minuti = ms / (60*1'000'000);
    ms = ms % (60*1'000'000);
    t.secondi = ms / 1'000'000;
    t.microsecondi = ms % 1'000'000;
}

// Inizializzazione comoda della struct se l'inizializzazione non è possibile restituisce false
bool crea_traccia(Traccia_t& t, int16_t o, int8_t m, int8_t s, int32_t ms){
    if ( o<0 || m<0 || s<0 || ms<0 ) {
        return false;
    }
    t.ore = o;
    t.microsecondi = ms;
    t.minuti = m;
    t.secondi = s;
    micro_to_time(t,time_to_micro(&t));
    return true;
}

// Somma la durata delle tracce ed il risultato va in traccia1
void accoda(Traccia_t& a, Traccia_t& b) {
    uint64_t alpha = time_to_micro(&a);
    uint64_t beta = time_to_micro(&b);

    alpha += beta;
    micro_to_time(a,alpha);
}

// Sottrae la durata di traccia2 da traccia1 se possibile e restituisce true altrimenti restituisce false e non effettua
// la sottrazione. La sottrazione non è valida traccia1 diventa negativa
bool taglia(Traccia_t& a, const Traccia_t* b) {
    if (piu_breve(a,*b)) return false;
    uint64_t alpha = time_to_micro(&a);
    uint64_t beta = time_to_micro(b);

    alpha -= beta;
    micro_to_time(a,alpha);
}

// True se traccia1 è meno lunga di traccia2
bool piu_breve(const Traccia_t& a, const Traccia_t& b) {
    uint64_t alpha = time_to_micro(&a);
    uint64_t beta = time_to_micro(&b);

    return alpha<beta;
}

// True se traccia1 è più lunga traccia2
bool piu_lunga(const Traccia_t& a, const Traccia_t& b) {
    uint64_t alpha = time_to_micro(&a);
    uint64_t beta = time_to_micro(&b);

    return alpha>beta;
}

// True se e solo se traccia1 e traccia2 sono uguali
bool stessa_durata(const Traccia_t& a, const Traccia_t& b) {
    uint64_t alpha = time_to_micro(&a);
    uint64_t beta = time_to_micro(&b);

    return alpha==beta;
}

// Stampa un traccia in modo formattato HHH:MM:SS.MS
void stampa_info( Traccia_t* traccia) {
    cout << (int)traccia->ore <<":"<< (int)traccia->minuti <<":"<< (int)traccia->secondi <<":"<< (int)traccia->microsecondi<< endl;
}
