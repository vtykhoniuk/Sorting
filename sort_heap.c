#include "sort_heap.h"

void sink(uint32_t a[], int i, size_t N)
{
    while (2*i+1 < N) {
        int max_id = 2*i + 1;
        if (max_id+1 < N && a[max_id] < a[max_id+1])
            max_id++;

        if (a[i] < a[max_id])
            swap(a, i, max_id);
        else
            break;

        i = max_id;
    }
}

void sort_heap(uint32_t a[], size_t N)
{
    // Building heap
    for (int i = N/2+1; i >= 0; --i)
        sink(a, i, N);

    while (N > 1) {
        swap(a, 0, --N);
        sink(a, 0, N);
    }
}

void sort_heap_system(uint32_t a[], size_t N)
{
    heapsort(a, N, sizeof(*a), cmp_uint32);
}
