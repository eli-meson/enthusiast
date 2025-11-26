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
   uint16_t arr[] = {5, 3, 8, 7};

   TEST_ASSERT_EQUAL(3 ,sortArray("5387", 4)[0]);
}

void test_summOfDiff(void){

   uint16_t arr1[] = {1, 2, 4, 5};
   uint16_t arr2[] = {3, 4, 6, 7};

   TEST_ASSERT_EQUAL(8, SumOfDiff(arr1, arr2));
}