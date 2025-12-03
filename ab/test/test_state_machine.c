#include "unity.h"
#include "fff.h"
#include "state_machine.h"

void setUp(void) {

}

void tearDown(void) {

}

extern State_t mState;

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

void test_cmd() {
    accept_byte('[');
    accept_byte('A');

    TEST_ASSERT_EQUAL(STATE_LEN, mState);
}

