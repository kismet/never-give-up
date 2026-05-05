#include "../includes/types.h"
#include "../includes/libs.h"

//Sottrare a c1 il valore di c2 se possibile e restiutisce TRUE, se non è possibile sottrare c2 a c1 allora non fa nulla
//e restituisce FALSE. La sottrazione non si può fare se il risultato viene negativo.
bool scarto(const Cronometro_t& c1, const Cronometro_t* c2){

}
// Stampa il calore del Cronometro usando il formato  HHH:MM:SS.MS
void mostra(Cronometro_t* c){

}
//TRUE se e solo se c1 precede c2
bool precede(const Cronometro_t& c1, const Cronometro_t& c2) {

}

// Inizializzazione comoda della struct se l'inizializzazione
void inizializza(Cronometro_t& c, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {

}

//TRUE se e solo se c2 precede c1
bool segue(const Cronometro_t& c1, const Cronometro_t& c2) {

}

//TRUE se e solo se c1 e c2 rappresentano lo stesso Cronometro
bool coincide(const Cronometro_t& c1, const Cronometro_t& c2){
    if (c1.microsecondi == c2.microsecondi && c1.minuti == c2.minuti && c1.secondi == c2.secondi && c1.ore == c2.ore) {
        return true;
    }
    return false;
}

//Aggiunge a c1 il valore di c2
void somma_tempi(Cronometro_t& c1, Cronometro_t& c2){
    c1.microsecondi += c2.microsecondi;
    c1.minuti += c2.minuti;
    c1.minuti += c2.minuti;
    c1.ore += c2.ore;
}