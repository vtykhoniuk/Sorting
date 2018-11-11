#include "sort_quick.h"

#include <stdlib.h>


void sort_quick_system(uint32_t a[], size_t N)
{
    qsort(a, N, sizeof(*a), cmp_uint32);
}
