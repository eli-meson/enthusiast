#include "unity.h"
#include "fff.h"

#include "a.h"
#include "mock_b.h"

void setUp(void)
{
}

void tearDown(void) 
{
}

// void test_a_auto_mock(void)
// {
//    TEST_ASSERT_NOT_CALLED(B_Sum);
//    TEST_ASSERT_NOT_CALLED(B_Mult);
//    TEST_ASSERT_NOT_CALLED(B_Div2);

//    A_SumOfN(10);

//    TEST_ASSERT_CALLED(B_Sum);
//    TEST_ASSERT_CALLED(B_Mult);
//    TEST_ASSERT_CALLED(B_Div2);

//    TEST_ASSERT_EQUAL(10, B_Sum_fake.arg0_val);
//    TEST_ASSERT_EQUAL(1, B_Sum_fake.arg1_val);
// }
void test_finalsumm(void){

   uint16_t arr1[] = {1, 2, 4, 5};
   uint16_t arr2[] = {3, 4, 7, 6};
   uint16_t size = 4;

   TEST_ASSERT_EQUAL(8, finalsumm(arr1, arr2, size));
}

// static uint16_t B_Sum_callback(uint16_t x, uint16_t y)
// {
//    return x + y;
// }
// static uint16_t B_Mult_callback(uint16_t x, uint16_t y)
// {
//    return x * y;
// }
// static uint16_t B_Div2_callback(uint16_t x)
// {
//    return x / 2;
// }
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
