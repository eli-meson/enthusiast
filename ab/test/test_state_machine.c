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
    

    accept_bytes('[');
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

    accept_bytes(aCH);

    TEST_ASSERT_EQUAL(STATE_START, mState);
    
}

TEST_CASE('[')
void test_invalid_CMD_goes_to_cmd(char s){
    
    mState = STATE_CMD;

    accept_bytes(s);

    TEST_ASSERT_EQUAL(STATE_CMD, mState);
    
}

TEST_CASE('A')
TEST_CASE('B')
TEST_CASE('C')
void test_invalid_CMD_goes_to_LEN(char s){
    
    mState = STATE_CMD;

    accept_bytes(s);

    TEST_ASSERT_EQUAL(STATE_LEN, mState);
    
}

TEST_CASE(']')
void test_invalid_CMD_goes_to_START(char s){
    
    mState = STATE_CMD;

    accept_bytes(s);

    TEST_ASSERT_EQUAL(STATE_START, mState);
    
}

TEST_CASE('0')
void test_invalid_LEN_goes_to_END(char s){
    
    mState = STATE_LEN;

    accept_bytes(s);

    TEST_ASSERT_EQUAL(STATE_END, mState);
    
}

TEST_CASE(']')
void test_invalid_END_goes_to_START(char s){
    
    mState = STATE_END;

    accept_bytes(s);

    TEST_ASSERT_EQUAL(STATE_START, mState);
    
}

void test_valid_string(void){

    accept_bytes('[');
    accept_bytes('A');
    accept_bytes('0');
    
    TEST_ASSERT_EQUAL_STRING("[A0]", accept_bytes(']'));

    accept_bytes('[');
    accept_bytes('S');
    accept_bytes('0');

    TEST_ASSERT_EQUAL_STRING("[S0]", accept_bytes(']'));
    
}

void test_max_valid_packet_size(void){

    accept_bytes('[');
    accept_bytes('Z');
    accept_bytes('9');
    accept_bytes('F');
    accept_bytes('e');
    accept_bytes('D');
    accept_bytes('C');
    accept_bytes('B');
    accept_bytes('a');
    accept_bytes('9');
    accept_bytes('8');
    accept_bytes('7');
    accept_bytes('6');
    accept_bytes('5');
    accept_bytes('4');
    accept_bytes('3');
    accept_bytes('2');
    accept_bytes('1');
    accept_bytes('0');
    accept_bytes('f');
    accept_bytes('E');


    TEST_ASSERT_EQUAL_STRING("[Z9FeDCBa986543210fE]", accept_bytes(']'));
    
}