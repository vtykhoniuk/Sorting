#include <stdio.h>

#include "array_utils.h"


void fill_array(uint32_t a[], size_t n)
{
    if (n == 0)
        return;

    for (u_int i = 0; i < n; a[i++] = arc4random_uniform(100));
}


void print_array(uint32_t a[], size_t n)
{
    printf("Printing array:\n");

    for (u_int i = 0; i < n; printf("%d ", a[i++]));

    printf("\n");
}


bool is_sorted(uint32_t a[], size_t n)
{
    if (n < 2)
        return true;

    for (u_int i = 1; i < n; ++i)
        if (a[i-1] > a[i])
            return false;

    return true;
}
