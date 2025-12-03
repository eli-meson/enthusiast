#include "unity.h"
#include "fff.h"

#include "a.h"
#include "mock_b.h"

#define TEST_CASE(...)

extern State_t state;
extern int len;
extern int data_counter;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_blank(void) {
   TEST_ASSERT_NULL(accept_byte('['));
}
// VALID TEST CASES

TEST_CASE('[')
void test_start_to_cmd(char aCh)
{
   //GIVEN
   state = STATE_START;
   //WHEN
   char* ptr = accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_CMD);
   TEST_ASSERT_EQUAL('[', ptr[0]);
}

TEST_CASE('A')
TEST_CASE('M')
TEST_CASE('Z')
void test_cmd_to_len(char aCh)
{
   //GIVEN
   state = STATE_CMD;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_LEN);
}


TEST_CASE('[')
void test_cmd_to_len_incorrect_bracket(char aCh)
{
   //GIVEN
   state = STATE_CMD;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_CMD);
}

TEST_CASE('0')
void test_len_to_end(char aCh)
{
   //GIVEN
   state = STATE_LEN;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_END);
}

TEST_CASE('4')
TEST_CASE('b')
TEST_CASE('M')
void test_data_to_end(char aCh)
{
   //GIVEN
   state = STATE_DATA;
   len = 5;
   data_counter = 4;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_END);
}

TEST_CASE(']')
void test_end_to_start(char aCh)
{
   //GIVEN
   state = STATE_END;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_START);
}

// INVALID TEST CASES

TEST_CASE('1')
void test_start_to_cmd_invalid(char aCh) {
   //GIVEN
   state = STATE_START;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_START);
}

TEST_CASE('6')
TEST_CASE('2')
TEST_CASE('a')
void test_cmd_to_len_invalid(char aCh)
{
   //GIVEN
   state = STATE_CMD;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_START);
}

TEST_CASE('[')
void test_cmd_to_len_invalid_bracket(char aCh)
{
   //GIVEN
   state = STATE_CMD;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_CMD);
}

void test_max_valid_packet() {
   //GIVEN
   state = STATE_START;
   //WHEN
   char* ptr = accept_byte('[');
   ptr = accept_byte('B');
   ptr = accept_byte('9');
   ptr = accept_byte('A');
   ptr = accept_byte('b');
   ptr = accept_byte('c');
   ptr = accept_byte('1');
   ptr = accept_byte('2');
   ptr = accept_byte('3');
   ptr = accept_byte('f');
   ptr = accept_byte('5');
   ptr = accept_byte('7');
   ptr = accept_byte('8');
   ptr = accept_byte('9');
   ptr = accept_byte('c');
   ptr = accept_byte('d');
   ptr = accept_byte('e');
   ptr = accept_byte('4');
   ptr = accept_byte('2');
   ptr = accept_byte('1');
   ptr = accept_byte('a');
   ptr = accept_byte('a');
   ptr = accept_byte('a');
   ptr = accept_byte('a');
   ptr = accept_byte('a');
   ptr = accept_byte('a');

   ptr = accept_byte(']');


   //THEN
   TEST_ASSERT_EQUAL(state, STATE_START);
   TEST_ASSERT_EQUAL_STRING("[B9Abc123f5789cde421a]", ptr);
}

void test_start_to_cmd_2(void)
{
   //GIVEN
   char expected[] = {'[', 'A', '0', ']'};
   state = STATE_START;
   //WHEN
   char* ptr = accept_byte('[');
   ptr = accept_byte('A');
   ptr = accept_byte('0');
   ptr = accept_byte(']');
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_START);
   TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, ptr, 4);
}