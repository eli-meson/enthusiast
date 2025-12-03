#include "state_machine.h"
#include <stddef.h>

State_t mState = STATE_NONE;

char* accept_byte(char c){
    mState = STATE_START;
    return NULL;
}

