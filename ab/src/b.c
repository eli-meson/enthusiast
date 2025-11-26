#include "b.h"

#include <assert.h>

#define ARRAY_SIZE(x)   (sizeof(x)/sizeof(x[0]))

int* B_Sort(int n[]) {
    int size = ARRAY_SIZE(n);

    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arrj[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    

}
int B_Find_Diff(int x, int y) {
    if (x > y) {return x - y;}
    else {return y - x;}
}
