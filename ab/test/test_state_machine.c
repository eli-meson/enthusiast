#include "unity.h"
#include "fff.h"
#include "state_machine.h"

#define TEST_CASE(...)

extern State_t mState;

void setUp(void) {
    mState = STATE_START;
}

void tearDown(void) {

}

void test_accept_byte(){
    char *result = accept_byte('a');
    TEST_ASSERT_NULL(result);
}

void test_state() {
    accept_byte('a');
    TEST_ASSERT_EQUAL(STATE_START, mState);
}

void test_transition() {
    accept_byte('[');
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
}

TEST_CASE('A', 3)
TEST_CASE('[', 2)
TEST_CASE('3', 1)
void test_cmd(char c, int expected) {
    mState = STATE_CMD;
    accept_byte(c);

    TEST_ASSERT_EQUAL(expected, mState);
}




TEST_CASE('3', 4)
TEST_CASE('[', 2)
TEST_CASE('A', 1)
TEST_CASE('0', 5)
void test_len(char c, int expected){
    mState = STATE_LEN;
    accept_byte(c);

    TEST_ASSERT_EQUAL(expected, mState);
}

TEST_CASE('3', 4)
TEST_CASE('b', 4)
TEST_CASE('D', 4)
TEST_CASE('[', 2)
TEST_CASE(']', 1)
TEST_CASE('$', 5)
void test_data(char c, int expected){
    mState = STATE_LEN;
    accept_byte(c);

    TEST_ASSERT_EQUAL(expected, mState);
}
