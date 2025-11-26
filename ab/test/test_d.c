#include "unity.h"
#include "fff.h"
#include <string.h>

#include "d.h"
#include "mock_c.h"


void test_d_auto_mock(void)
{
   //TEST_ASSERT_NOT_CALLED(read_file);

   int total;
   int result = read_file("src/fake.txt", &total);
   

   //TEST_ASSERT_CALLED(read_file);

   TEST_ASSERT_EQUAL(1, result);
   TEST_ASSERT_EQUAL(1, read_file("src/fake.txt", &total));
   TEST_ASSERT_EQUAL(0, read_file(NULL, &total));
   TEST_ASSERT_EQUAL(0, read_file("src/fake.txt", NULL));
   TEST_ASSERT_EQUAL(0, read_file(NULL, NULL));
}


static int getLineValue_callback(char* line)
{
   if (strchr(line, 'a') != NULL) {
    return 1;
   } else if (strchr(line, 'b') != NULL) {
    return 0;
   }  else if (strchr(line, 'c') != NULL) {
    return -1;
   }  
   return -100;
}

void test_a_custom_fake(void)
{
   getLineValue_fake.custom_fake = getLineValue_callback;
   TEST_ASSERT_NOT_CALLED(getLineValue);

   TEST_ASSERT_EQUAL(1, getLineValue("a"));
   TEST_ASSERT_EQUAL(0, getLineValue("b"));
   TEST_ASSERT_EQUAL(-1, getLineValue("c"));

   TEST_ASSERT_CALLED_TIMES(3, getLineValue);
}
