#include "b.h"

#include <assert.h>
#include <stdlib.h>
#include <math.h>



void sortArray(uint16_t * arr, uint16_t size){
    qsort(arr, size, sizeof(uint16_t));
}

uint16_t SumOfDiff(const uint16_t * arr1, const uint16_t * arr2)
{
    uint16_t size = sizeof(arr1)/sizeof(uint16_t);
    if (sizeof(arr1) == sizeof(arr2))
    {
        uint16_t sum = 0; 
        for (int i = 0; i < size; ++i){
            sum += abs(arr1[i] - arr2[i]);
        }
        return sum;
    }

    return 0;
}