#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include "sort_utils.h"

void sort_insertion(uint32_t a[], size_t n);
void sort_insertion_optimized_aux(uint32_t a[], int lo, int hi);
void sort_insertion_optimized(uint32_t a[], size_t n);

#endif // SORT_INSERTION_H
