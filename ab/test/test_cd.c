#include "unity.h"
#include <stdio.h>

#include "c.h"
#include "d.h"

void test_cd_integration(void)
{
   int total;
   TEST_ASSERT_EQUAL(1, read_file("src/fake.txt", &total));
   TEST_ASSERT_EQUAL(0, read_file(NULL, &total));
   TEST_ASSERT_EQUAL(0, read_file("src/fake.txt", NULL));
   TEST_ASSERT_EQUAL(0, read_file(NULL, NULL));
}