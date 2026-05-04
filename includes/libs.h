#ifndef NEVER_GIVE_UP_LIBS_H
#define NEVER_GIVE_UP_LIBS_H

// Inizializzazione comoda della struct se l'inizializzazione non è possibile restituisce false
bool crea_traccia(Traccia_t& t, uint16_t o, uint8_t m, uint8_t s, uint32_t ms);

// True se traccia1 è meno lunga di traccia2
bool piu_breve(const Traccia_t& traccia1, const Traccia_t& traccia2);

// True se traccia1 è più lunga traccia2
bool piu_lunga(const Traccia_t& traccia1, const Traccia_t& traccia2);

// True se e solo se traccia1 e traccia2 sono uguali
bool stessa_durata(const Traccia_t& traccia1, const Traccia_t& traccia2);

// Somma la durata delle tracce ed il risultato va in traccia1
void accoda(Traccia_t& traccia1, Traccia_t& traccia2);

// Sottrae la durata di traccia2 da traccia1 se possibile e restituisce true altrimenti restituisce false e non effettua
// la sottrazione. La sottrazione non è valida traccia1 diventa negativa
bool taglia(Traccia_t& traccia1, const Traccia_t* traccia2);

// Stampa un traccia in modo formattato HHH:MM:SS.MS
void stampa_info( Traccia_t* traccia);

#endif //NEVER_GIVE_UP_LIBS_H