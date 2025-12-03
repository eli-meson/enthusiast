#include "state_machine.h"
#include "unity.h"
#include "fff.h"

#define TEST_CASE(...)

extern state_t mState;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_null(void){
    

    TEST_ASSERT_NULL(accept_bytes('['));
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
    accept_bytes('A');
    TEST_ASSERT_EQUAL(STATE_LEN, mState);
    accept_bytes('0');
    TEST_ASSERT_EQUAL(STATE_END, mState);
    accept_bytes('[');
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
    accept_bytes('A');
    accept_bytes('0');
    accept_bytes(']');
    TEST_ASSERT_EQUAL(STATE_START, mState);
}

TEST_CASE('=')
TEST_CASE('{')
TEST_CASE('6')
void test_invalid_CMD_goes_to_start(char aCH){
    
    mState = STATE_CMD;

    TEST_ASSERT_NULL(accept_bytes(aCH));

    TEST_ASSERT_EQUAL(STATE_START, mState);
    
}

TEST_CASE('[')
void test_invalid_CMD_goes_to_cmd(char s){
    
    mState = STATE_CMD;

    TEST_ASSERT_NULL(accept_bytes(s));

    TEST_ASSERT_EQUAL(STATE_CMD, mState);
    
}

TEST_CASE('A')
TEST_CASE('B')
TEST_CASE('C')
void test_invalid_CMD_goes_to_LEN(char s){
    
    mState = STATE_CMD;

    TEST_ASSERT_NULL(accept_bytes(s));

    TEST_ASSERT_EQUAL(STATE_LEN, mState);
    
}

TEST_CASE('0')
void test_invalid_LEN_goes_to_END(char s){
    
    mState = STATE_LEN;

    TEST_ASSERT_NULL(accept_bytes(s));

    TEST_ASSERT_EQUAL(STATE_END, mState);
    
}

TEST_CASE(']')
void test_invalid_END_goes_to_START(char s){
    
    mState = STATE_END;

    TEST_ASSERT_NULL(accept_bytes(s));

    TEST_ASSERT_EQUAL(STATE_START, mState);
    
}
