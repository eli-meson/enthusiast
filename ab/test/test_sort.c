#include "unity.h"
#include "fff.h"

#include "sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_compare()
{
    int t_num1 = 5, t_num2 = 10;
    void *v_num1 = (void *) &t_num1;
    void *v_num2 = (void *) &t_num2;

    TEST_ASSERT_EQUAL(-1, compare(v_num1, v_num2));
    TEST_ASSERT_EQUAL(1, compare(v_num2, v_num1));
    TEST_ASSERT_EQUAL(0, compare(v_num1, v_num1));
}

void test_sort()
{
    int test_list[] = {9,8,7,5,4,3,2,1};
    int test_size = sizeof(test_list)/sizeof(test_list[0]);

    sort_list(test_list, test_size);

    int expected_list[] = {1,2,3,4,5,7,8,9};

    TEST_ASSERT_EQUAL_INT_ARRAY(expected_list, test_list, test_size);
}

typedef struct 
{
    int small_val;
    int large_val;
} compare_test_case_t;

static compare_test_case_t compare_cases[] = {
    {5, 6},
    {0, 2},
    {10, 100},
    {INT32_MIN, INT32_MAX},
    {-1, 50},
    {}
};

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))
#define TEST_SUIT_SIZE  (ARRAY_SIZE(compare_cases))

void test_compare_suite(void)
{

   for(int idx = 0; idx < TEST_SUIT_SIZE; idx++)
   {
       compare_test_case_t testCase = compare_cases[idx];
       void *v_num1 = (void *) &testCase.small_val;
       void *v_num2 = (void *) &testCase.large_val;
    
       TEST_ASSERT_EQUAL(-1, compare(v_num1, v_num2));
       TEST_ASSERT_EQUAL(1, compare(v_num2, v_num1));
       TEST_ASSERT_EQUAL(0, compare(v_num1, v_num1));
   }
}

