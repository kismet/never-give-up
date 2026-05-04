//
// Created by stefy on 04/05/2026.
//

#ifndef NEVER_GIVE_UP_TYPES_H
#define NEVER_GIVE_UP_TYPES_H

#include <cstdint>  // per uintXX_t

typedef struct Traccia {
    uint64_t ore;
    uint8_t minuti;
    uint8_t secondi;
    uint32_t microsecondi;
} Traccia_t;

#endif //NEVER_GIVE_UP_TYPES_H