#include "c.h"
#include <stdio.h>
#include <stdlib.h>

int getLineValue(char* line) {
    int a;
    int b;
    sscanf(line, "%d %d\n", &a, &b);
    int diff = a - b;
    return abs(diff);
}

