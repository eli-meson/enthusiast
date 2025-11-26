#include "distance.h"
#include <string.h>
#include "sort.h"

int find_total_distance(int *first, int *second, int size)
{
    // TODO - replace with allocating with malloc and freeing at function end
    int first_copy[100] = {};
    int second_copy[100] = {};

    memcpy(first_copy, first, size*sizeof(first[0]));
    memcpy(second_copy, second, size*sizeof(second[0]));

    sort_list(first_copy, size);
    sort_list(second_copy, size);

    int total_distance = 0;
    for(int i = 0; i < size; i++)
    {
        int small = (first_copy[i] <= second_copy[i]) ? first_copy[i] : second_copy[i];
        int large = (first_copy[i] >= second_copy[i]) ? first_copy[i] : second_copy[i];
        total_distance += large - small;
    }

    return total_distance;
}