//
// Created by stefy on 04/05/2026.
//

#ifndef NEVER_GIVE_UP_TYPES_H
#define NEVER_GIVE_UP_TYPES_H

#include <cstdint>

typedef struct Batteria {
    uint64_t hours;
    uint8_t minutes;
    uint8_t seconds;
    uint32_t microseconds;
} Batteria_t;

#endif //NEVER_GIVE_UP_TYPES_H