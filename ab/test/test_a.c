#include "unity.h"
#include "fff.h"

#include "a.h"
#include "mock_b.h"

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

void test_a_auto_mock(void)
{
   TEST_ASSERT_NOT_CALLED(B_Sort);
   TEST_ASSERT_NOT_CALLED(B_Find_Diff);

   int toSort1[] = {2, 3, 2, 7, 1};
   int toSort2[] = {2, 3, 2, 7, 1};
   int b = A_Array_Of_Distances(toSort1, toSort2);

   TEST_ASSERT_CALLED(B_Sort);
   TEST_ASSERT_CALLED(B_Find_Diff);

   // TEST_ASSERT_EQUAL(toSort1, B_Sum_fake.arg0_val);
   // TEST_ASSERT_EQUAL(toSort2, B_Sum_fake.arg1_val);
}

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}
static int* B_Sort_callback(int *n) {
   int size = ARRAY_SIZE(n);
   qsort(n, size, sizeof(int), compare);
   return n;
}
static int B_Find_Diff_callback(int x, int y) {
    if (x > y) {return x - y;}
    else {return y - x;}
}
// void test_a_custom_fake(void)
// {
//    B_Sum_fake.custom_fake = B_Sum_callback;
//    B_Mult_fake.custom_fake = B_Mult_callback;
//    B_Div2_fake.custom_fake = B_Div2_callback;

//    TEST_ASSERT_NOT_CALLED(B_Sum);
//    TEST_ASSERT_NOT_CALLED(B_Mult);
//    TEST_ASSERT_NOT_CALLED(B_Div2);

//    TEST_ASSERT_EQUAL(1, A_SumOfN(1));
//    TEST_ASSERT_EQUAL(15, A_SumOfN(5));
//    TEST_ASSERT_EQUAL(55, A_SumOfN(10));

//    TEST_ASSERT_CALLED_TIMES(3, B_Sum);
//    TEST_ASSERT_CALLED_TIMES(3, B_Mult);
//    TEST_ASSERT_CALLED_TIMES(3, B_Div2);

//    TEST_ASSERT_EQUAL(1, B_Sum_fake.arg0_history[0]);
//    TEST_ASSERT_EQUAL(5, B_Sum_fake.arg0_history[1]);
//    TEST_ASSERT_EQUAL(10, B_Sum_fake.arg0_history[2]);
// }
