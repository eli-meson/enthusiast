#include "a.h"
#include "b.h"

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))

/**
 * n(n+1)/2
 */
// uint32_t A_SumOfN(uint8_t n)
// {
//    return B_Div2(B_Mult(n, B_Sum(n,1)));
// }

int A_SumOfDistances(int n[])
{
   int sum = 0;
   for (int i = 0; i < ARRAY_SIZE(A_Array_Of_Distances); i++) {
      sum += A_Array_Of_Distances[i];
   }
   return sum;
}

int* A_Array_Of_Distances(int n1[] , int n2[]) {
   int size = ARRAY_SIZE(n1);
   n1[] = B_Sort(n1);
   n2[] = B_Sort(n2);
   int res[size];
   for (int i = 0; i < size; i++) {
      res[i] = B_Find_Diff(n1[i], n2[i]);
   }
}
