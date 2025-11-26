#include "a.h"
#include "b.h"
#include <stdio.h>

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))

/**
 * n(n+1)/2
 */
// uint32_t A_SumOfN(uint8_t n)
// {
//    return B_Div2(B_Mult(n, B_Sum(n,1)));
// }

int A_SumOfDistances(int *n)
{
   int sum = 0;
   for (int i = 0; i < ARRAY_SIZE(n); i++) {
      sum += n[i];
   }
   return sum;
}

int A_Array_Of_Distances(int *n1, int *n2) {
   int size = ARRAY_SIZE(n1);
   int *sorted_n1 = B_Sort(n1);
   int *sorted_n2 = B_Sort(n2);
   int res[size];
   for (int i = 0; i < size; i++) {
      printf("%d \n", sorted_n1[i]);
      res[i] = B_Find_Diff(sorted_n1[i], sorted_n2[i]);
   }
   return A_SumOfDistances(res);
}
