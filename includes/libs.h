#ifndef NEVER_GIVE_UP_LIBS_H
#define NEVER_GIVE_UP_LIBS_H

// Inizializzazione comoda della struct se l'inizializzazione non è possibile restituisce false
void inizializza(Cronometro_t& c, uint16_t o, uint8_t m, uint8_t s, uint32_t ms);

//TRUE se e solo se c1 precede c2
bool precede(const Cronometro_t& c1, const Cronometro_t& c2);

//TRUE se e solo se c2 precede c1
bool segue(const Cronometro_t& c1, const Cronometro_t& c2);

//TRUE se e solo se c1 e c2 rappresentano lo stesso Cronometro
bool coincide(const Cronometro_t& c1, const Cronometro_t& c2);

//Aggiunge a c1 il valore di c2
void somma_tempi(Cronometro_t& c1, Cronometro_t& c2);

//Sottrare a c1 il valore di c2 se possibile e restiutisce TRUE, se non è possibile sottrare c2 a c1 allora non fa nulla
//e restituisce FALSE. La sottrazione non si può fare se il risultato viene negativo.
bool scarto(const Cronometro_t& c1, const Cronometro_t* c2);

// Stampa il calore del Cronometro usando il formato  HHH:MM:SS.MS
void mostra(Cronometro_t* c);

#endif //NEVER_GIVE_UP_LIBS_H