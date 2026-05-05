#include "../includes/types.h"
#include "../includes/libs.h"

#include <iostream>

// Autore: (Calcagni Luca)
// Data:   (2026/05/05)
// Classe: 3CI
// Fila:    (C)

//Sottrare a c1 il valore di c2 se possibile e restiutisce TRUE, se non è possibile sottrare c2 a c1 allora non fa nulla
//e restituisce FALSE. La sottrazione non si può fare se il risultato viene negativo.
bool scarto(Cronometro_t& c1, const Cronometro_t& c2){
    if (c1.ore -= c2.ore < 0) {
        return false;
    }
    if (c1.minuti -= c2.minuti < 0) {
        return false;
    }
    if (c1.secondi -= c2.secondi < 0) {
        return false;
    }
    if (c1.microsecondi -= c2.microsecondi < 0) {
        return false;
    }
    c1.ore -= c2.ore;
    c1.minuti -= c2.minuti;
    c1.secondi -= c2.secondi;
    c1.microsecondi -= c2.microsecondi;
}
// Stampa il calore del Cronometro usando il formato  HHH:MM:SS.MS
void mostra(Cronometro_t& c){
    std::cout << (int)c.ore << ":" << (int)c.minuti << ":" << (int)c.secondi << ":" << (int)c.microsecondi << std::endl;
}

//TRUE se e solo se c1 precede c2
bool precede(const Cronometro_t& c1, const Cronometro_t& c2){
    return true;
}

// Inizializzazione comoda della struct
bool inizializza(Cronometro_t& c, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {
    if (o > 0 || m > 0 && m < 59 || s > 0 && s < 59 || ms > 0 && ms < 999) {
        return true;
    }
    return false;
}

//TRUE se e solo se c2 precede c1
bool segue(const Cronometro_t& c1, const Cronometro_t& c2) {
    return true;
}

//TRUE se e solo se c1 e c2 rappresentano lo stesso Cronometro
bool coincide(const Cronometro_t& c1, const Cronometro_t& c2){
    if (c1.microsecondi == c2.microsecondi && c1.minuti == c2.minuti && c1.secondi == c2.secondi && c1.ore == c2.ore) {
        return true;
    }
    return false;
}

//Aggiunge a c1 il valore di c2
void somma_tempi(Cronometro_t& c1,const Cronometro_t& c2){
    c1.microsecondi += c2.microsecondi;
    c1.minuti += c2.minuti;
    c1.minuti += c2.minuti;
    c1.ore += c2.ore;
}