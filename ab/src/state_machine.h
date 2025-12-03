#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stdio.h>

typedef enum {
    STATE_NONE,
    STATE_START,
    STATE_CMD,
    STATE_LEN,
    STATE_DATA,
    STATE_END
} state_t;

char * accept_bytes(char c);

#endif