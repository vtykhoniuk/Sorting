#include "sort_insertion.h"


void sort_insertion(uint32_t a[], size_t n)
{
    if (n < 2)
        return;

    for (uint i = 1; i < n; ++i) {
        uint32_t k = a[i];
        for (int j = i-1; j >= 0 && a[j] > k; --j)
            swap(a, j, j+1);
    }
}


void sort_insertion_optimized_aux(uint32_t a[], int lo, int hi)
{
    if (lo == hi)
        return;

    for (uint i = lo+1; i <= hi; ++i) {
        uint32_t k = a[i];
        int j = i;
        for (; j > lo && a[j-1] > k; --j)
            a[j] = a[j-1];

        a[j] = k;
    }
}

void sort_insertion_optimized(uint32_t a[], size_t n)
{
    sort_insertion_optimized_aux(a, 0, n-1);
}
