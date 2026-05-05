// Autore: (Landucci Gianmarco)
// Data:   (2026/05/05)
// Classe: 3CI
// Fila:    (C)

#ifndef NEVER_GIVE_UP_TYPES_H
#define NEVER_GIVE_UP_TYPES_H

#include <cstdint>

typedef struct Cronometro {
    uint32_t microsecondi;
    uint8_t secondi;
    uint8_t minuti;
    uint64_t ore;

    const Cronometro &operator-=(const Cronometro * c2);
} Cronometro_t;

#endif //NEVER_GIVE_UP_TYPES_H