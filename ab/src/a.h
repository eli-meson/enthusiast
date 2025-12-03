#ifndef A_H
#define A_H

#include <stdint.h>

typedef enum {
    STATE_NONE,
    STATE_START,
    STATE_CMD,
    STATE_LEN,
    STATE_DATA,
    STATE_END
} State_t;

char* accept_byte(char c);


#endif // A_H
