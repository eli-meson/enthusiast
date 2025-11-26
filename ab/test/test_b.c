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


void test_B_Sort(void)
{
   int toSort[] = {2, 3, 2, 7, 1};
   int *ptr;
   ptr = &toSort;
   int expected[] = {1, 2, 2, 3, 7};
   int *received = B_Sort(ptr);

   for(int i = 0; i < 5; i++) {
      printf("%x", *received);
      TEST_ASSERT_EQUAL_INT16_MESSAGE(expected[i], received[i], "Sorted.");
   }
   
}

void test_Find_Diff(void)
{
   int expected = 5;
   int received = B_Find_Diff(5, 10);
   TEST_ASSERT_EQUAL_INT16_MESSAGE(expected, received, "Diffed.");
   
}

// A single run test 
// void test_B_Sum_single(void)
// {
//    uint16_t expected = 25;
//    uint16_t received = B_Mult(5, 5);

//    TEST_ASSERT_EQUAL_INT16_MESSAGE(expected, received, "5 x 5 = 25");
// }

