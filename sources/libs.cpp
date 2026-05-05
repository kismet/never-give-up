#include "../includes/types.h"
#include "../includes/libs.h"

bool create(Tempo_t& t, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {
    Tempo_t tempo;
    tempo.ore=o;
    tempo.minuti=m;
    tempo.secondi=s;
    tempo.microsecondi=ms;

    return true;
}

bool before(const Tempo_t& tempo1, const Tempo_t& tempo2) {
    if (tempo1.microsecondi<tempo2.microsecondi) {
        if (tempo1.secondi<tempo2.secondi) {
            if (tempo1.minuti<tempo2.minuti) {
                if (tempo1.ore<tempo2.ore) {
                    return true;
                }
            }
        }
    }
    else {
        return false;
    }
}