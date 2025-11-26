#include "unity.h"
#include "fff.h"

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

    TEST_ASSERT_EQUAL(0, distance);
}