#include "state_machine.h"
#include <stddef.h>

State_t mState = STATE_START;

char * accept_byte(char c) {
    char * res = NULL;
    switch (mState) {
        case STATE_START:
            if (c == '[') {
                mState = STATE_CMD;
            }
        case STATE_CMD:
            if (c <= 'Z' && c >= 'A') {
                mState = STATE_LEN;
            }
    }
    return res;
}