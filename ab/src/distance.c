#include "distance.h"
#include <string.h>
#include "sort.h"

int find_total_distance(int *first, int *second, int size)
{
    // TODO - replace with allocating with malloc and freeing at function end
    int first_copy[100] = {};
    int second_copy[100] = {};

    memcpy(first_copy, first, sizeof(first));
    memcpy(second_copy, second, sizeof(second));

    sort_list(first_copy, size);
    sort_list(second_copy, size);

    int total_distance = 0;
    for(int i = 0; i < size; i++)
    {
        total_distance += first_copy[i] - second_copy[i];
    }

    return total_distance;
}