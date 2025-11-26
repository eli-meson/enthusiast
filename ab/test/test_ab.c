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

void test_ab(void)
{
   TEST_ASSERT_EQUAL(8, finalsumm("1245","3476"));
}
