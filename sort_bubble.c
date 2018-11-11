#include "sort_bubble.h"


void sort_bubble(uint32_t a[], size_t n)
{
    if (n < 2)
        return;

    uint k = 0;
    bool sorted;

    do {
        sorted = true;
        for (u_int i = 1; i < n - k; ++i)
            if (a[i-1] > a[i]) {
                swap(a, i-1, i);
                sorted = false;
            }
        ++k;
    } while (!sorted);
}
