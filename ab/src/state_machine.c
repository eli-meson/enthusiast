#include "state_machine.h"
#include <stdio.h>

state_t mState;
static char buffer [23];

char * accept_bytes(char c){

    mState = STATE_START;
    if(c == '[') {
        mState = STATE_CMD;
        memset(buffer, 0, sizeof(buffer));
        buffer[0] = c;
    }
    else if(c >= 'A' && c <= 'Z' ){
        mState = STATE_LEN;
        buffer[1] = c;
    }
    else if (c >= '0'){
        mState = STATE_END;
        buffer[2] = c;
        
    }
    else if (c >= '1' && c <= '9'){
        mState = STATE_DATA;
        
        for(int i = 3; sizeof(buffer) < 21; i++){
            buffer[i] = c;
        } 
    }
    else if (c == ']'){
        mState = STATE_START;
        buffer[22] = c;
    }
    else {
        mState = STATE_START;
    }
    
    
    printf("%s\n", buffer);
    return buffer;
}