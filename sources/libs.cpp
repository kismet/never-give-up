#include "../includes/types.h"
#include "../includes/libs.h"

bool setup(Batteria_t& c, uint16_t o, uint8_t m, uint8_t s, uint32_t ms) {
    bool inizializzazioneCorretta = true;

    c.hours = o;
    if (c.hours == NULL) {
        inizializzazioneCorretta = false;
    }
    c.minutes = m;
    if (c.minutes == NULL) {
        inizializzazioneCorretta = false;
    }
    c.seconds = s;
    if (c.seconds == NULL) {
        inizializzazioneCorretta = false;
    }
    c.microseconds = ms;
    if (c.microseconds == NULL) {
        inizializzazioneCorretta = false;
    }

    return inizializzazioneCorretta;
}