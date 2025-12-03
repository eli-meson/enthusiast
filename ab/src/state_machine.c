#include "state_machine.h"
#include <stddef.h>
#include <ctype.h>

State_t mState = STATE_START;

#define IS_CMD(X) (((X) >= 'A') && ((X) <= 'Z'))
#define IS_LEN(X) ((X) >= '0' && (X) <= '9')

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
    } else if (mState == STATE_LEN){
        if (c == '0') {
            mState = STATE_END;        
        } else if (IS_LEN(c)){
            // properly implement later
            mState = STATE_DATA;
        } else if (c == '['){
            mState = STATE_CMD;
        } else {
            mState = STATE_START;
        }
    }
    return NULL;
}

