#include "state_machine.h"
#include <stddef.h>

State_t mState = STATE_START;

char* accept_byte(char c){

    if (mState == STATE_START && c == '[') {
        mState = STATE_CMD;
    }
    return NULL;
}

