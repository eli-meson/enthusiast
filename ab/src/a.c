#include "a.h"
#include "b.h"

/**
 * n(n+1)/2
 */
// uint32_t A_Exp(uint8_t n, uint8_t exp)
// {
//    return B_Mult(n, A_Exp(n, exp - 1));
// }

// uint32_t A_Fact(uint8_t num)
// {
//    uint16_t summ = 1; 
//    for (int i = 1; i < num; ++i){
//       summ = B_Mult(summ, i); 
//    }
// }

uint16_t finalsumm(uint16_t * arr1, uint16_t * arr2, uint16_t size)
{
   sortArray(arr1, size);
   sortArray(arr2, size);

   return SumOfDiff(arr1, arr2);
}