#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort_bubble.h"
#include "sort_insertion.h"
#include "sort_merge.h"
#include "sort_heap.h"
#include "sort_quick.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE 1000
#endif

typedef void (*sort_worker)(uint32_t[], size_t);

typedef struct {
    const char* name;
    sort_worker worker;
} Sorter;


int main()
{
    uint32_t* A = malloc(ARRAY_SIZE * sizeof(uint32_t));
    uint32_t* b = malloc(ARRAY_SIZE * sizeof(uint32_t));
    fill_array(A, ARRAY_SIZE);

    Sorter s[] = {
#ifndef SKIP_BUBBLE_SORT
        {"Bubble Sort", sort_bubble},
#endif
#ifndef SKIP_INSERTION_SORT
        {"Insertion Sort", sort_insertion},
        {"Insertion Sort (optimized)", sort_insertion_optimized},
#endif
        {"Merge Sort", sort_merge},
        {"Merge Sort (optimized)", sort_merge_optimized},
        {"Merge Sort (system)", sort_merge_system},
        {"Heap Sort", sort_heap},
        {"Heap Sort (system)", sort_heap_system},
        {"Quick Sort (system)", sort_quick_system},
    };

    for (uint i = 0; i < sizeof(s) / sizeof(*s); ++i) {
        // Rebuilding original array
        memcpy(b, A, ARRAY_SIZE * sizeof(uint32_t));

        time_t c = clock();

        // Actual sort
        s[i].worker(b, ARRAY_SIZE);

        printf("%d. %s - %ld ms\n",
            i+1,
            s[i].name,
            (clock()-c)*1000L/CLOCKS_PER_SEC);

        // Checking whether we sorted correctly
        if (!is_sorted(b, ARRAY_SIZE))
            fprintf(stderr,
                "The array was not properly sorted by [%s]\n",
                s[i].name);
    }

    free(A);
    free(b);

    exit(EXIT_SUCCESS);
}
