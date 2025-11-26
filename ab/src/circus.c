#include "circus.h"
#include <stdio.h>

void announce(char *buf, char *name)
{
    sprintf(buf, "Presenting: %s", name);
}