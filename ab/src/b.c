#include "b.h"

#include <assert.h>

uint16_t B_Sum(uint16_t x, uint16_t y)
{
   return x + y;
}

uint16_t B_Mult(uint16_t x, uint16_t y)
{
   assert(x < UINT8_MAX);
   assert(y < UINT8_MAX);

   uint16_t result = 0;

   for(uint8_t iter = 0; iter < y; iter++)
   {
       result += x;
   }

   return result;
}

uint16_t B_Div2(uint16_t x)
{
    return x >> 1;
}
