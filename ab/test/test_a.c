#include "unity.h"
#include "fff.h"

#include "a.h"
#include "mock_b.h"

#define TEST_CASE(...)

extern State_t state;
extern int len;
extern int counter;
extern char buffer[22];

void setUp(void)
{
}

void tearDown(void)
{
}

void test_blank(void) {
   TEST_ASSERT_NULL(accept_byte('['));
}

TEST_CASE('[')
void test_start_to_cmd(char aCh)
{
   //GIVEN
   state = STATE_START;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_CMD);
   TEST_ASSERT_EQUAL('[', buffer);
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

TEST_CASE('6')
TEST_CASE('2')
TEST_CASE('a')
void test_cmd_to_len_incorrect(char aCh)
{
   //GIVEN
   state = STATE_CMD;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_START);
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
   counter = 4;
   //WHEN
   accept_byte(aCh);
   //THEN
   TEST_ASSERT_EQUAL(state, STATE_END);
}

void _test_valid_data(void) {
   char buffer = '[';

   // Successful Case
   TEST_ASSERT_EQUAL("[", accept_byte('['));
   // Test that state is 'looking for cmd'
   TEST_ASSERT_EQUAL("[B", accept_byte('B'));
   // Test that state is length
   TEST_ASSERT_EQUAL("[B4", accept_byte('4'));
   // Test that state is getting data
   TEST_ASSERT_EQUAL("[B48", accept_byte('8'));
   TEST_ASSERT_EQUAL("[B485", accept_byte('5'));
   TEST_ASSERT_EQUAL("[B4859", accept_byte('9'));
   TEST_ASSERT_EQUAL("[B48592", accept_byte('2'));
   // Test that state is looking for end
   TEST_ASSERT_EQUAL("[B48592]", accept_byte(']'));
   // Test looking for start


   // Unsuccessful Case
   TEST_ASSERT_EQUAL("", accept_byte('3'));   // should be looking for start

   TEST_ASSERT_EQUAL("[", accept_byte('['));
   TEST_ASSERT_EQUAL("", accept_byte(' '));   // should be looking for start
}