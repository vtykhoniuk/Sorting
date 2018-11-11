#include <string.h>

#include "sort_merge.h"
#include "sort_insertion.h"


void merge(uint32_t a[], int lo, int mid, int hi, uint32_t aux[])
{
    size_t n = hi - lo + 1;
    memcpy(aux+lo, a+lo, n*sizeof(*a));

    for (int k = lo, i = lo, j = mid + 1; k <= hi; k++)
        if (i > mid)                a[k] = aux[j++];
        else if (j > hi)            a[k] = aux[i++];
        else if (aux[i] < aux[j])   a[k] = aux[i++];
        else                        a[k] = aux[j++];
}


void sort(uint32_t a[], int lo, int hi, uint32_t aux[])
{
    if (hi <= lo)
        return;

    int mid = lo + (hi-lo)/2;

    sort(a, lo, mid, aux);
    sort(a, mid+1, hi, aux);
    merge(a, lo, mid, hi, aux);
}


void sort_merge(uint32_t a[], size_t n)
{
    uint32_t* aux = malloc(n * sizeof(uint32_t));
    sort(a, 0, n-1, aux);
    free(aux);
}


void sort_optimized(uint32_t a[], int lo, int hi, uint32_t aux[])
{
    if (hi - lo <= 7) {
        sort_insertion_optimized_aux(a, lo, hi);
        return;
    }

    int mid = lo + (hi-lo)/2;

    sort_optimized(a, lo, mid, aux);
    sort_optimized(a, mid+1, hi, aux);
    if (a[mid] <= a[mid+1])
        return;
    merge(a, lo, mid, hi, aux);
}


void sort_merge_optimized(uint32_t a[], size_t n)
{
    uint32_t* aux = malloc(n * sizeof(uint32_t));
    sort_optimized(a, 0, n-1, aux);
    free(aux);
}

void sort_merge_system(uint32_t a[], size_t N)
{
    mergesort(a, N, sizeof(*a), cmp_uint32);
}
