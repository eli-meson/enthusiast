#include "cat.h"
#include "circus.h"
#include <stdio.h>

int main(void)
{
    char buf[50] = {};
    cat_say_hello(buf);
    printf("%s\n", buf);
}