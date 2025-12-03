#include "unity.h"
#include "fff.h"

#include "state_machine.h"

extern State_t mState;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_accept_byte(void){
    char *data = accept_byte('[');
    TEST_ASSERT_EQUAL(NULL, data);
}

void test_start_to_cmd(void){
    char *data = accept_byte('[');
    TEST_ASSERT_EQUAL(NULL, data);
    TEST_ASSERT_EQUAL(STATE_START, mState);
}