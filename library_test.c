#include "library.h"
#include <stdio.h>

int main() 
{
    int left = 4;
    int right = 9;

    int result = add_external(left, right);
    printf("Result is: %d\n", result);
    return 0;
}

