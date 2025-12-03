#include "unity.h"
#include "fff.h"

#include "state_machine.h"
#define TEST_CASE(...)

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

// Start state tests 

void test_start_to_cmd(void){
    TEST_ASSERT_EQUAL(STATE_START, mState);
    char *data = accept_byte('[');
    TEST_ASSERT_EQUAL(NULL, data);
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
}

TEST_CASE('A')
TEST_CASE('B')
TEST_CASE('!')
void test_start_to_self(char ch){
    TEST_ASSERT_NULL(accept_byte(ch));
    TEST_ASSERT_EQUAL(STATE_START, mState);
}

// CMD state tests 

TEST_CASE('A')
TEST_CASE('B')
TEST_CASE('C')
void test_cmd_to_len(char ch){
    char *data = accept_byte('[');
    data = accept_byte(ch);
    TEST_ASSERT_EQUAL(NULL, data);
    TEST_ASSERT_EQUAL(STATE_LEN, mState);
}

// Test that receiving open bracket on cmd stays at same state
void test_cmd_to_self(void){
    TEST_ASSERT_EQUAL(STATE_START, mState);
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_EQUAL(STATE_CMD, mState);

    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
}

// Test receiving invalid char at cmd goes back to start
TEST_CASE('9')
TEST_CASE('!')
TEST_CASE('b')
void test_cmd_to_start(char ch){
    mState = STATE_CMD;
    char *data = accept_byte(ch);
    TEST_ASSERT_EQUAL(STATE_START, mState);
}

void test_len_to_end(void){
    mState = STATE_LEN;
    TEST_ASSERT_NULL(accept_byte('0'));
    TEST_ASSERT_EQUAL(STATE_END, mState);
}

TEST_CASE('1')
TEST_CASE('5')
TEST_CASE('9')
void test_len_to_data(char ch) {
    mState = STATE_LEN;
    TEST_ASSERT_NULL(accept_byte(ch));
    TEST_ASSERT_EQUAL(STATE_DATA, mState);
}

void test_len_to_cmd(void) {
    mState = STATE_LEN;
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
}

TEST_CASE('!')
TEST_CASE('b')
TEST_CASE('X')
void test_len_to_start(char ch) {
    mState = STATE_LEN;
    TEST_ASSERT_NULL(accept_byte(ch));
    TEST_ASSERT_EQUAL(STATE_START, mState);
}

void test_end_min_valid_return(void) {
    TEST_ASSERT_EQUAL(STATE_START, mState);
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('B'));
    TEST_ASSERT_NULL(accept_byte('0'));

    char *data = accept_byte(']');
    TEST_ASSERT_EQUAL(STATE_START, mState);
    TEST_ASSERT_EQUAL_STRING("[B0]", data);
}

void test_end_to_cmd(void) {
    mState = STATE_END;
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_EQUAL(STATE_CMD, mState);
}

TEST_CASE('b')
TEST_CASE('!')
TEST_CASE('G')
void test_end_to_start_no_return(char ch) {
    mState = STATE_END;
    TEST_ASSERT_NULL(accept_byte(ch));
    TEST_ASSERT_EQUAL(STATE_START, mState);
}

void test_valid_packet_with_data(void) {
    TEST_ASSERT_EQUAL(STATE_START, mState);
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('A'));
    TEST_ASSERT_NULL(accept_byte('2'));

    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('2'));
    TEST_ASSERT_NULL(accept_byte('3'));
    TEST_ASSERT_NULL(accept_byte('4'));

    char *data = accept_byte(']');
    TEST_ASSERT_EQUAL(STATE_START, mState);
    TEST_ASSERT_EQUAL_STRING("[A21234]", data);
}

void test_max_valid_packet(void) {
    TEST_ASSERT_NULL(accept_byte('['));
    TEST_ASSERT_NULL(accept_byte('Z'));
    TEST_ASSERT_NULL(accept_byte('9'));

    TEST_ASSERT_NULL(accept_byte('2'));
    TEST_ASSERT_NULL(accept_byte('5'));
    TEST_ASSERT_NULL(accept_byte('a'));
    TEST_ASSERT_NULL(accept_byte('F'));
    TEST_ASSERT_NULL(accept_byte('d'));
    TEST_ASSERT_NULL(accept_byte('3'));
    TEST_ASSERT_NULL(accept_byte('9'));
    TEST_ASSERT_NULL(accept_byte('A'));
    TEST_ASSERT_NULL(accept_byte('1'));
    TEST_ASSERT_NULL(accept_byte('9'));
    TEST_ASSERT_NULL(accept_byte('f'));
    TEST_ASSERT_NULL(accept_byte('5'));
    TEST_ASSERT_NULL(accept_byte('2'));
    TEST_ASSERT_NULL(accept_byte('7'));
    TEST_ASSERT_NULL(accept_byte('b'));
    TEST_ASSERT_NULL(accept_byte('D'));
    TEST_ASSERT_NULL(accept_byte('c'));
    TEST_ASSERT_NULL(accept_byte('9'));

    char *data = accept_byte(']');
    TEST_ASSERT_EQUAL_STRING("[Z925aFd39A19f527bDc9]", data);
    TEST_ASSERT_EQUAL(STATE_START, mState);
}