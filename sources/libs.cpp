#include "../includes/types.h"
#include "../includes/libs.h"
#include <iostream>
using namespace std;

// Inizializzazione comoda della struct se l'inizializzazione non è possibile restituisce false
bool crea_traccia(Traccia_t& t, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {

    if (o<0) {
        return false;
    }
    if (m<0) {
        return false;
    }
    if (s<0) {
        return false;
    }
    if (ms<0) {
        return false;
    }
    while (ms>=1000000) {
        s++;
        ms-=1000000;
    }
    while (s>=60) {
        m++;
        s-=60;
    }
    while (m>=60) {
        o++;
        m-=60;
    }
        t.ore=o;
        t.minuti=m;
        t.secondi=s;
        t.microsecondi=ms;
    return true;
}

// Somma la durata delle tracce ed il risultato va in traccia1
void accoda(Traccia_t& traccia1, Traccia_t& traccia2) {
    traccia1.ore=traccia1.ore+traccia2.ore;
    traccia1.minuti=traccia1.minuti+traccia2.minuti;
    traccia1.secondi=traccia1.secondi+traccia2.secondi;
    traccia1.microsecondi=traccia1.microsecondi+traccia2.microsecondi;
    while (traccia1.microsecondi>=1000000) {
         traccia1.secondi++;
        traccia1.microsecondi-=1000000;
    }
    while (traccia1.secondi>=60) {
        traccia1.minuti++;
        traccia1.secondi-=60;
    }
    while (traccia1.minuti>=60) {
        traccia1.ore++;
        traccia1.minuti-=60;
    }
}

// Sottrae la durata di traccia2 da traccia1 se possibile e restituisce true altrimenti restituisce false e non effettua
// la sottrazione. La sottrazione non è valida traccia1 diventa negativa
bool taglia(Traccia_t& traccia1, const Traccia_t* traccia2) {
    Traccia_t tmp=traccia1;
    if (tmp.ore-traccia2->ore<0) {
        return false;
    }
    if (tmp.minuti-traccia2->minuti<0) {
        return false;
    }
    if (tmp.secondi-traccia2->secondi<0) {
        return false;
    }
    if (tmp.microsecondi-traccia2->microsecondi<0) {
        return false;
    }
        traccia1.ore=traccia2->ore;
        traccia1.minuti=traccia2->minuti;
        traccia1.secondi=traccia2->secondi;
        traccia1.microsecondi=traccia2->microsecondi;
    return true;
}

// True se traccia1 è meno lunga di traccia2
bool piu_breve(const Traccia_t& traccia1, const Traccia_t& traccia2) {
    if (traccia1.ore>=traccia2.ore) {
        return false;
    }
    if (traccia1.minuti>=traccia2.minuti) {
        return false;
    }
    if (traccia1.secondi>=traccia2.secondi) {
        return false;
    }
    if (traccia1.microsecondi>=traccia2.microsecondi) {
        return false;
    }
    return true;
}

// True se traccia1 è più lunga traccia2
bool piu_lunga(const Traccia_t& traccia1, const Traccia_t& traccia2) {
    if (traccia1.ore<=traccia2.ore) {
        return false;
    }
    if (traccia1.minuti<=traccia2.minuti) {
        return false;
    }
    if (traccia1.secondi<=traccia2.secondi) {
        return false;
    }
    if (traccia1.microsecondi<=traccia2.microsecondi) {
        return false;
    }
    return true;
}

// True se e solo se traccia1 e traccia2 sono uguali
bool stessa_durata(const Traccia_t& traccia1, const Traccia_t& traccia2) {
    if (traccia1.ore!=traccia2.ore) {
        return false;
    }
    if (traccia1.minuti!=traccia2.minuti) {
        return false;
    }
    if (traccia1.secondi!=traccia2.secondi) {
        return false;
    }
    if (traccia1.microsecondi!=traccia2.microsecondi) {
        return false;
    }
    return true;
}

// Stampa un traccia in modo formattato HHH:MM:SS.MS
void stampa_info( Traccia_t* traccia) {

    cout << (int)traccia->ore <<":"<< (int)traccia->minuti <<":"<< (int)traccia->secondi <<":"<< (int)traccia->microsecondi<< endl;
}
