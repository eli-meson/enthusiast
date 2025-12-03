

char* accept_byte(char c);

typedef enum {
    STATE_START,
    STATE_CMD,
    STATE_LEN,
    STATE_END,
    STATE_DATA
} State_t;