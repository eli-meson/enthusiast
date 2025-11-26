#include "unity.h"
#include "fff.h"
#include <stdio.h>

#include "cat.h"
#include "mock_circus.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void announce_callback(char *buf, char *name)
{
    sprintf(buf, "Announce: %s", name);
}

void test_mock_circus() 
{

    announce_fake.custom_fake = announce_callback;

    char buf[50] = {};
    cat_say_hello(buf);

    TEST_ASSERT_EQUAL_STRING("Announce: cat", buf);
}