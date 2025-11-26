#include "d.h"
#include "c.h"
#include <stdio.h>

int read_file(const char* filename, int* total) {
    FILE *in;
    *total = 0;
    in = fopen(filename, "r");
    if (in == NULL) {
        return 0;
    }
    char buffer[50];
    while (fgets(buffer, sizeof(buffer), in) != NULL) {
        int w = getLineValue(buffer);
        *total += w;
    }
    return 1;
}

