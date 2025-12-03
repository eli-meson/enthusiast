#include "state_machine.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

State_t mState;
char buffer[19];
int length;

char * accept_byte(char c) {
    static int pos;

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
                length = ctoi(c);
                pos = 0;
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

        case STATE_DATA:
        if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
            buffer[pos] = c;
            pos++;
        }
        else if (c == '[') {
            mState = STATE_CMD;
        }
        break;
    }
    return res;
}