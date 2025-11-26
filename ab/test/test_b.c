#include "unity.h"

#include "b.h"

#define MAX_ARG_VALUE                       (10)
#define TEST_CASE(...)

void setUp(void)
{
}

void tearDown(void)
{
}

void test_sort(void){
   TEST_ASSERT_EQUAL("3578" ,sortArray("5387", 4));
}

void test_summOfDiff(void){

   uint16_t arr1[] = {1, 2, 4, 5};
   uint16_t arr2[] = {3, 4, 6, 7};

   TEST_ASSERT_EQUAL(8, SumOfDiff(arr1, arr2));
}