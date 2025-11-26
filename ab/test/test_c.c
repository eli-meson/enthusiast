#include "unity.h"

#include "c.h"


void test_a_auto_mock(void)
{
   TEST_ASSERT_NOT_CALLED(getLineValue);

   getLineValue("aaa");

   TEST_ASSERT_CALLED(getLineValue);

   TEST_ASSERT_EQUAL(-1, getLineValue(NULL));
   TEST_ASSERT_EQUAL(3, getLineValue("1 4"));
   TEST_ASSERT_EQUAL(0, getLineValue("3"));
   TEST_ASSERT_EQUAL(1, getLineValue("3 4 5 3 2 5 6"));
   TEST_ASSERT_EQUAL(-1, getLineValue("  "));
}