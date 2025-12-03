#include "unity.h"
#include "fff.h"

#include "state_machine.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_accept_byte(void){
    char *data = accept_byte('a'); 
    TEST_ASSERT_EQUAL(NULL, data);
}