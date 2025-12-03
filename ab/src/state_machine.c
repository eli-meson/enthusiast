#include "state_machine.h"
#include <stddef.h>
#include <ctype.h>

State_t mState = STATE_START;

#define IS_CMD(X) (((X) >= 'A') && ((X) <= 'Z'))

char* accept_byte(char c){

    if (mState == STATE_START) {
        if (c == '[') {
            mState = STATE_CMD;
        }
    } else if (mState == STATE_CMD) {
        if (isupper(c)) {
           mState = STATE_LEN; 
        } else if (c != '[') {
            mState = STATE_START;
        }
    }
    return NULL;
}

