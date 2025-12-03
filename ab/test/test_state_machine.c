#include "unity.h"
#include "fff.h"

#include "state_machine.h"

extern State_t mState;

void setUp(void)
{
    mState = STATE_START;
}

void tearDown(void)
{
}

void test_accept_byte(void){
    char *data = accept_byte('[');
    TEST_ASSERT_EQUAL(NULL, data);
}

void test_start_to_cmd(void){
    TEST_ASSERT_EQUAL(STATE_START, mState);
    char *data = accept_byte('[');
    TEST_ASSERT_EQUAL(NULL, data);
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
}