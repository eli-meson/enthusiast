#include "state_machine.h"
#include <stddef.h>
#include <ctype.h>

State_t mState = STATE_START;
char fsm_buf[23] = {0};
char data_len = 0; // length of the data in packet
char nibbles_written = 0;

#define IS_CMD(X) (((X) >= 'A') && ((X) <= 'Z'))
#define IS_LEN(X) ((X) >= '0' && (X) <= '9')

#define IS_DATA(X) (((X) >= '0' && (X) <= '9') || \
                    ((X) >= 'A' && (X) <= 'F') || \
                    ((X) >= 'a' && (X) <= 'f'))

char* accept_byte(char c){

    if (mState == STATE_START) {
        fsm_buf[0] = '[';
        if (c == '[') {
            mState = STATE_CMD;
        }

    } else if (mState == STATE_CMD) {
        if (isupper(c)) {
           fsm_buf[1] = c;
           mState = STATE_LEN; 
        } else if (c != '[') { // stay at same state if input is '['
            mState = STATE_START;
        }

    } else if (mState == STATE_LEN) {
        data_len = 0;
        nibbles_written = 0;
        if (c == '0') {
            fsm_buf[2] = '0';
            mState = STATE_END;        
        } else if (IS_LEN(c)){
            data_len = c - '0';
            fsm_buf[2] = c;
            mState = STATE_DATA;

        } else if (c == '['){
            mState = STATE_CMD;
        } else {
            mState = STATE_START;
        }

    } else if (mState == STATE_DATA) {
        if (c == '['){
            mState = STATE_CMD;
        } else if (!IS_DATA(c)){
            mState = STATE_START;
        } else { // else state writes to buffer
            fsm_buf[3 + nibbles_written++] = c;
            if (nibbles_written == data_len*2){
                mState = STATE_END;
            }
        } 

    } else if (mState == STATE_END) {
        if ( c == ']') {
            mState = STATE_START;
            int packet_end = 2 + (data_len*2) + 1;
            fsm_buf[packet_end] = ']';
            fsm_buf[packet_end + 1] = '\0';
            return fsm_buf;
        } else if (c == '['){
            mState = STATE_CMD;
        } else {
            mState = STATE_START;
        }
            
    }
    return NULL;
}

