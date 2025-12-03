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

// TEST_CASE('3', 4)
// TEST_CASE('b', 4)
// TEST_CASE('D', 4)
// TEST_CASE('[', 2)
// TEST_CASE(']', 1)
// TEST_CASE('$', 5)
// void test_data(char c, int expected){
//     mState = STATE_LEN;
//     accept_byte(c);

//     TEST_ASSERT_EQUAL(expected, mState);
// }

void test_full() {


    accept_byte('[');
    accept_byte('A');
    accept_byte('0');
    char * result = accept_byte(']');

    TEST_ASSERT_EQUAL_STRING("[A0]", result);
    // TEST_ASSERT_EQUAL("[A0]", result);
}
void test_full2() {
    accept_byte('[');
    accept_byte('A');
    accept_byte('0');

    accept_byte('[');
    accept_byte('A');
    accept_byte('0');
    char * result = accept_byte(']');

    TEST_ASSERT_EQUAL_STRING("[A0]", result);
    // TEST_ASSERT_EQUAL("[A0]", result);
}

void test_full3() {
    accept_byte('[');
    accept_byte('A');
    accept_byte('0');

    char * result = accept_byte('S');

    TEST_ASSERT_NULL(result);
    TEST_ASSERT_EQUAL(1, mState);
}

extern int length;

void test_full4() {
    accept_byte('[');
    accept_byte('A');
    accept_byte('1');

    TEST_ASSERT_EQUAL(2,  length);

    accept_byte('3');
    accept_byte('f');

    TEST_ASSERT_EQUAL(0, length);

    char * result = accept_byte(']');

    TEST_ASSERT_EQUAL_STRING("[A13f]", result);
}

void test_max() {

    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('Z'));
    TEST_ASSERT_NULL(accept_byte('9'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_EQUAL_STRING("[Z9111111111111111111]", accept_byte(']'));
}

void test_max_start() {
    TEST_ASSERT_NULL(accept_byte('['));

    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('Z'));
    TEST_ASSERT_NULL(accept_byte('9'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_EQUAL_STRING("[Z9111111111111111111]", accept_byte(']'));
}

void test_max_cmd() {
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('Z'));

    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('Z'));
    TEST_ASSERT_NULL(accept_byte('9'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_EQUAL_STRING("[Z9111111111111111111]", accept_byte(']'));
}

void test_max_len() {
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('Z'));
    TEST_ASSERT_NULL(accept_byte('9'));

    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('Z'));
    TEST_ASSERT_NULL(accept_byte('9'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_EQUAL_STRING("[Z9111111111111111111]", accept_byte(']'));
}
