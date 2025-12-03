#include "state_machine.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

State_t mState;
char buffer[23];
int pos;
int length;

void reset() {
    pos = 0;
    memset(buffer, 0, sizeof(buffer));
}

char * accept_byte(char c) {

    char * res = NULL;
    switch (mState) {
        case STATE_START:
            if (c == '[') {
                reset();
                mState = STATE_CMD;
                buffer[pos] = c;
                pos++;
            }
            break;
        case STATE_CMD:
            if (c <= 'Z' && c >= 'A') {
                mState = STATE_LEN;
                buffer[pos] = c;
                pos++;
            } else if (c == '[') {
                reset();
                mState = STATE_CMD;
                buffer[pos] = 0;
            }else  {
                mState = STATE_START;
            }
            break;
        case STATE_LEN:
            if (c <= '9' && c >= '1') {
                mState = STATE_DATA;
                buffer[pos] = c;
                length = ((c - '1') + 1) * 2;
                pos++;
            }
            else if (c == '[') {
                reset();
                mState = STATE_CMD;
                buffer[pos] = c;
            }
            else if (c == '0') {
                mState = STATE_END;
                buffer[pos] = c;
                pos++;
            }
            else  {
                mState = STATE_START;
            }
            break;

        // case STATE_DATA:
        // if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
        //     buffer[pos] = c;
        //     pos++;
        // }
        // else if (c == '[') {
        //     mState = STATE_CMD;
        // }
        // break;
        case STATE_DATA:
            if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
                buffer[pos] = c;
                pos++;
                length--;
                if (length <= 0) {
                    mState = STATE_END;
                }
            }
            else if (c == '[')  {
                reset();
                mState = STATE_CMD;
                buffer[pos] = '[';
                pos++;
            }
            else {
                mState = STATE_START;
            }
            break;

        case STATE_END:
            if (c == ']') {
                buffer[pos] = c;
                pos++;
                buffer[pos] = '\0';
                res = buffer;
                mState = STATE_START;
            }else if (c == '[') {
                reset();
                mState = STATE_CMD;
                buffer[pos] = c;
                pos++;
            }
            else  {
                mState = STATE_START;
            }
            break;
    }

    // if (mState == STATE_START || STATE_CMD) {
    //     length = -1;
    // }
    return res;
}