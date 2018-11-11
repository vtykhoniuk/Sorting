#include "sort_utils.h"


void swap(uint32_t a[], uint i, uint j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}


int cmp_uint32(const void *a, const void *b)
{
    return *(uint32_t*)a - *(uint32_t*)b;
}
