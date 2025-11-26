#include "unity.h"
#include <stdio.h>
#include "c.h"


void test_c_auto(void)
{
   //TEST_ASSERT_NOT_CALLED(getLineValue("aaaa"));

   getLineValue("aaa");

   //TEST_ASSERT_CALLED(getLineValue("aaaa"));

   TEST_ASSERT_EQUAL(-1, getLineValue(NULL));
   TEST_ASSERT_EQUAL(3, getLineValue("1 4"));
   TEST_ASSERT_EQUAL(0, getLineValue("3"));
   TEST_ASSERT_EQUAL(1, getLineValue("3 4 5 3 2 5 6"));
   TEST_ASSERT_EQUAL(-1, getLineValue("  "));
}