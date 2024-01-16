#include "library.h"
#include <stdio.h>

int add_external(int left, int right)
{
    printf("Trying to add 2x %d to %d\n", left, right);
    return 2 * left + right;
}