#include "b.h"

#include <assert.h>

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))


int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

void B_Sort(int *n) {
    printf("%p", (void*)n);
    int size = ARRAY_SIZE(n);
    qsort(n, size, sizeof(int), compare);
}
    // int size = ARRAY_SIZE(n);
    // int i, j, temp;
    // for(int i = 0; i < size-1; i++) {
    //     for(int j = 0; j < size-i-1; j++) {
    //         if(*(n + j) > *(n + j + i)) {
    //             temp = *(n + j);
    //             *(n + j) = *(n + j + 1);
    //             *(n + j + 1) = temp;
    //         }
    //     }
    // }
    


int B_Find_Diff(int x, int y) {
    if (x > y) {return x - y;}
    else {return y - x;}
}
