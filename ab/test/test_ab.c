#include "unity.h"
#include "fff.h"

#include "a.h"
#include "b.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ab_integration(void)
{
   TEST_ASSERT_EQUAL(1, A_SumOfN(1));
   TEST_ASSERT_EQUAL(15, A_SumOfN(5));
   TEST_ASSERT_EQUAL(55, A_SumOfN(10));
}
