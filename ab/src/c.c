#include "c.h"
#include <stdio.h>
#include <stdlib.h>

int getLineValue(char* line) {
    if(line == NULL) {
        return -1;
    }



    int a = NULL;
    int b = NULL;
    int result = sscanf(line, "%d %d", &a, &b);

    if (result == 1) {
        return 0;
    }


    int diff = a - b;
    int finalValue = abs(diff);

    if (a == NULL && b == NULL) {
        return -1;
    }
    return finalValue;
}

