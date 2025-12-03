#include "unity.h"
#include "fff.h"
#include "state_machine.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_accept_byte(){
    int *result = accept_byte('a');
    TEST_ASSERT_NULL(result);
}