//
// Created by stefy on 04/05/2026.
//

#ifndef NEVER_GIVE_UP_TYPES_H
#define NEVER_GIVE_UP_TYPES_H

#include <cstdint>

typedef struct Cronometro {
    uint32_t microsecondi;
    uint8_t secondi;
    uint8_t minuti;
    uint64_t ore;
} Cronometro_t;

#endif //NEVER_GIVE_UP_TYPES_H