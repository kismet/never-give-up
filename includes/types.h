//
// Created by stefy on 04/05/2026.
//

#ifndef NEVER_GIVE_UP_TYPES_H
#define NEVER_GIVE_UP_TYPES_H

#include <cstdint>  // per uintXX_t

typedef struct Tempo {
    uint64_t ore;  // Teoricamente sono illimitate...
    uint8_t minuti;
    uint8_t secondi;
    uint32_t microsecondi;
} Tempo_t;

#endif //NEVER_GIVE_UP_TYPES_H