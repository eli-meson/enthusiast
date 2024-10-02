#include "unity.h"

#include "b.h"

#define MAX_ARG_VALUE                       (10)
#define TEST_CASE(...)

void setUp(void)
{
}

void tearDown(void)
{
}

// A single run test 
void test_B_Sum_single(void)
{
   uint16_t expected = 25;
   uint16_t received = B_Mult(5, 5);

   TEST_ASSERT_EQUAL_INT16_MESSAGE(expected, received, "5 x 5 = 25");
}

// Test with a loop 
void test_B_Sum_loop(void)
{
   for (uint8_t args_x = 0; args_x < MAX_ARG_VALUE; args_x++)
   {
       for (uint8_t args_y = 0; args_y < MAX_ARG_VALUE; args_y++)
       {
           uint16_t expected = args_x * args_y;
           uint16_t received = B_Mult(args_x, args_y);
           TEST_ASSERT_EQUAL_INT16(expected, received);
       }
   }
}

// Helper function and explicit test names 
static void check_B_Mult(uint8_t args_x, uint8_t args_y, uint16_t expected)
{
   uint16_t received = B_Mult(args_x, args_y);
   TEST_ASSERT_EQUAL_INT16(expected, received);
}

void test_B_Mult_0_x_MAX(void) { check_B_Mult(0, MAX_ARG_VALUE, 0); }
void test_B_Mult_1_x_MAX(void) { check_B_Mult(1, MAX_ARG_VALUE, MAX_ARG_VALUE); }
void test_B_Mult_MAX_x_0(void) { check_B_Mult(MAX_ARG_VALUE, 0, 0); }
void test_B_Mult_MAX_x_1(void) { check_B_Mult(MAX_ARG_VALUE, 1, MAX_ARG_VALUE); }
void test_B_Mult_5_x_5(void) { check_B_Mult(5, 5, 25); }
void test_B_Mult_MAX_x_MAX(void) { check_B_Mult(MAX_ARG_VALUE, MAX_ARG_VALUE, MAX_ARG_VALUE * MAX_ARG_VALUE); }

// Test suite
typedef struct {
   uint8_t x;
   uint8_t y;
   uint16_t xy;
} BMult_TestCase_t;

static BMult_TestCase_t _testSuite[] = {
   { 0, MAX_ARG_VALUE, 0 },
   { 1, MAX_ARG_VALUE, MAX_ARG_VALUE },
   { MAX_ARG_VALUE, 0, 0 },
   { MAX_ARG_VALUE, 1, MAX_ARG_VALUE },
   { 5, 5, 25 },
   { MAX_ARG_VALUE, MAX_ARG_VALUE, MAX_ARG_VALUE * MAX_ARG_VALUE },
};

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))
#define TEST_SUIT_SIZE  (ARRAY_SIZE(_testSuite))

void test_B_Sum_testSuite(void)
{
   uint16_t expected[TEST_SUIT_SIZE];
   uint16_t recieved[TEST_SUIT_SIZE];

   for(uint8_t idx = 0; idx < TEST_SUIT_SIZE; idx++)
   {
       BMult_TestCase_t testCase = _testSuite[idx];
       expected[idx] = testCase.xy;
       recieved[idx] = B_Mult(testCase.x, testCase.y);
   }

   TEST_ASSERT_EQUAL_UINT16_ARRAY(expected, recieved, TEST_SUIT_SIZE);
}

// Parametrised test
TEST_CASE( 0, 10, 0, "0 x 10 = 0" )
TEST_CASE( 1, 10, 10, "1 x 10 = 10"  )
TEST_CASE( 10, 0, 0, "10 x 0 = 0"  )
TEST_CASE( 10, 1, 10, "10 x 1 = 10"  )
TEST_CASE( 5, 5, 25, "5 x 5 = 25"  )
TEST_CASE( 10, 10, 10 * 10, "10 x 10 = 100"  )
void test_B_Sum_param(uint16_t x, uint16_t y, uint16_t xy, char * message)
{
   TEST_ASSERT_EQUAL_INT16_MESSAGE(xy, B_Mult(x, y), message);
}
