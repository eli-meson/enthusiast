#include "unity.h"
#include "fff.h"

#include "mock_distance.h"
#include "sort.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static int find_total_distance_callback(int *first, int *second, int size)
{
    return 50;
}

void test_mock_distance()
{
    find_total_distance_fake.custom_fake = find_total_distance_callback;

    int x[5], y[5];
    int distance = find_total_distance(x, y, 5);

    TEST_ASSERT_EQUAL(50, distance);
}