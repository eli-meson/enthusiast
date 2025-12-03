#include "state_machine.h"
#include <stddef.h>

State_t mState;

char * accept_byte(char c) {
    char * res = NULL;
    switch (mState) {
        case STATE_START:
            if (c == '[') {
                mState = STATE_CMD;
            }
            break;
        case STATE_CMD:
            if (c <= 'Z' && c >= 'A') {
                mState = STATE_LEN;
            } else if (c == '[') {
                mState = STATE_CMD;
            }else  {
                mState = STATE_START;
            }
            break;
        case STATE_LEN:
            if (c <= '9' && c >= '1') {
                mState = STATE_DATA;
            }
            else if (c == '[') {
                mState = STATE_CMD;
            }
            else if (c == '0') {
                mState = STATE_END;
            }
            else  {
                mState = STATE_START;
            }
            break;
    }
    return res;
}