#include "unity.h"
#include "fff.h"

#include "cat.h"
#include "circus.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_announce_cat() 
{
    char buf[50] = {};
    cat_say_hello(buf);

    TEST_ASSERT_EQUAL_STRING("Presenting: cat", buf);
}