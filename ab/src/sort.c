#include <stdlib.h>
#include "sort.h"

int compare(const void *x, const void *y)
{
    int i_x = (*(int *)x);
    int i_y = (*(int *)y);
    
    if(i_x < i_y)
    {
        return -1;
    }
    else if(i_x > i_y)
    {
        return 1;
    }

    return 0;
}

void sort_list(int *list, int size)
{
    qsort(list, size - 1, sizeof(list[0]), compare);
}