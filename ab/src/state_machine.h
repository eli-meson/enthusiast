#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    STATE_NONE,
    STATE_START,
    STATE_CMD,
    STATE_LEN
} State_t;

char * accept_byte(char c);

#endif