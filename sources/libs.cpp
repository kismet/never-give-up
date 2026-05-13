#include "../includes/types.h"
#include "../includes/libs.h"
#include <iostream>

// Inizializzazione comoda della struct se l'inizializzazione non è possibile restituisce false
bool create(Tempo_t& t, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {

};

// True se tempo1 viene prima di tempo2
bool before(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    //LENZI non si usano così le struct
    if (tempo1 < tempo2) {
        return true;
    }

};

// True se tempo1 viene dopo tempo2
bool after(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    //LENZI non si usano così le struct
    if (tempo1 > tempo2) {
        return true;
    }
};

// True se e solo se tempo1 e tempo2 sono uguali
bool equal(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    //LENZI non si usano così le struct
    if (tempo1 == tempo2) {
        return true;
    }
};

// Somma i due tempi ed il risultato va in tempo1
void add(Tempo_t& tempo1, Tempo_t& tempo2) {
    //LENZI non si usano così le struct
    tempo1 = tempo1 + tempo2;
};

// Sottrae tempo2 da tempo1 se possibile e restituisce true altrimenti restituisce false non effettua la sottrazione
// il tempo non può mai essere negativo
bool diff(Tempo_t& tempo1, const Tempo_t* tempo2) {

};

// Stampa un tempo in modo formattato HHH:MM:SS.MS
void print( Tempo_t* tempo) {

};