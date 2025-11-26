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
   // TEST_ASSERT_EQUAL(1, A_SumOfN(1));
   // TEST_ASSERT_EQUAL(15, A_SumOfN(5));
   // TEST_ASSERT_EQUAL(55, A_SumOfN(10));

   int[] array1 = {3, 4, 2, 1, 3, 3};
   int[] array2 = {4, 3, 5, 3, 9, 3};
   TEST_ASSERT_EQUAL(11, A_Array_Of_Distances(array1, array2));
   //TEST_ASSERT_EQUAL(15, A_Array_Of_Distances(array1, array2));
   //TEST_ASSERT_EQUAL(55, A_Array_Of_Distances(array1, array2));
}
