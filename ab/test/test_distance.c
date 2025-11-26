#include "unity.h"
#include "fff.h"
#include <stdint.h>

#include "distance.h"
#include "sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_distance()
{
    int test_list1[] = {3, 4, 2, 1, 3, 3};
    int test_list2[] = {4, 3, 5, 3, 9, 3};
    int test_size = sizeof(test_list1)/sizeof(test_list1[0]);

    int distance = find_total_distance(test_list1, test_list2, test_size);

    TEST_ASSERT_EQUAL(11, distance);
}

void test_distance2()
{
    
    int test_list1[] = {1, INT32_MAX, 3, 4, 5, 6};
    int test_list2[] = {6, 5, 4, 3, 50, 1};
    int test_size = sizeof(test_list1)/sizeof(test_list1[0]);

    int expected_dist = INT32_MAX - 50;
    int distance = find_total_distance(test_list1, test_list2, test_size);

    TEST_ASSERT_EQUAL(expected_dist, distance);
}

void test_distance_diff_array_size()
{
    int test_list1[] = {1, 2, 3, 4, 5};
    int test_list2[] = {7, 6, 5, 4, 3, 2, 1};
    int test_size = sizeof(test_list1)/sizeof(test_list1[0]);

    int distance = find_total_distance(test_list1, test_list2, test_size);

    TEST_ASSERT_EQUAL(11, distance);
}