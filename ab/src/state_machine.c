#include "state_machine.h"
#include <stdio.h>

state_t mState;

char * accept_bytes(char c){

    mState = STATE_START;
    if(c == '[') {
        mState = STATE_CMD;
    }
    else if(c >= 'A' && c <= 'Z' ){
        mState = STATE_LEN;
    }
    else if (c == '0'){
        mState = STATE_END;
    }
    else if (c == ']'){
        mState = STATE_START;
    }
    else {
        mState = STATE_START;
    }
    printf("%c", c);
    return NULL;
}