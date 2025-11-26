#include "unity.h"
#include "fff.h"

#include "d.h"
#include "mock_c.h"


void test_d_auto_mock(void)
{
   TEST_ASSERT_NOT_CALLED(read_file);ceedling trrst:

   int total;
   int result = read_file("src/fake.txt", &total);

   TEST_ASSERT_CALLED(read_file);

   TEST_ASSERT_EQUAL(1, result);
}


int getLineValue(char* line)
{
   return 4;
}

void test_c_custom_fake(void)
{
   getLineValue.custom_fake = getLineValue;

   TEST_ASSERT_NOT_CALLED(getLineValue);
   int total;
   TEST_ASSERT_EQUAL(1, read_file("src/fake.txt", &total));

   TEST_ASSERT_CALLED_TIMES(4, getLineValue);

   //TEST_ASSERT_EQUAL(1, B_Sum_fake.arg0_history[0]);
   //TEST_ASSERT_EQUAL(5, B_Sum_fake.arg0_history[1]);
   //TEST_ASSERT_EQUAL(10, B_Sum_fake.arg0_history[2]);
}
