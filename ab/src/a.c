#include "a.h"
#include "b.h"

/**
 * n(n+1)/2
 */
uint32_t A_SumOfN(uint8_t n)
{
   return B_Div2(B_Mult(n, B_Sum(n,1)));
}
