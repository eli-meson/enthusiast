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