#include "unity.h"
#include "fff.h"

#include "a.h"
#include "mock_b.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_blank(void) {
   TEST_ASSERT_NULL(accept_byte('['));
}

void test_start(void)
{
   State_t state = STATE_NONE;
   TEST_ASSERT_EQUAL(state, STATE_NONE);
   TEST_ASSERT_EQUAL("[", accept_byte('['));
   TEST_ASSERT_EQUAL(state, STATE_START);

}

void test_valid_data(void) {
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