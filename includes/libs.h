#ifndef NEVER_GIVE_UP_LIBS_H
#define NEVER_GIVE_UP_LIBS_H

// Inizializzazione comoda della struct se l'inizializzazione non è possibile restituisce false
void setup(Batteria_t& c, uint16_t o, uint8_t m, uint8_t s, uint32_t ms);

//TRUE se e solo se c1 si scarica prima di  c2
bool minor_autonomia(const Batteria_t& c1, const Batteria_t& c2);

// Stampa il calore dell'autonomia usando il formato  HHH:MM:SS.MS
void stampa_autonomia(Batteria_t* c);

//TRUE se e solo se c1 si scarica dopo c2
bool maggior_autonomia(const Batteria_t& c1, const Batteria_t& c2);

//Aggiunge a c1 il valore di carica di c2
void ricarica(Batteria_t& c1, Batteria_t& c2);

//Sottrare a c1 il valore di carica c2 se possibile e restiutisce TRUE, se non è possibile sottrare c2 a c1 allora non
//fa nulla e restituisce FALSE. La sottrazione non si può fare se il risultato viene negativo.
bool scarica(const Batteria_t& c1, const Batteria_t* c2);

//TRUE se e solo se c1 e c2 rappresentano lo stesso Cronometro
bool stessa_autonomia(const Batteria_t& c1, const Batteria_t& c2);


#endif //NEVER_GIVE_UP_LIBS_H