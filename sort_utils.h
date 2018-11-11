#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include "array_utils.h"

// Swaps two values with indexes i and j from array a
void swap(uint32_t a[], uint i, uint j);

// Compares two unsigned int 32 integers (uses in system sorts)
int cmp_uint32(const void *, const void *);

#endif // SORT_UTILS_H
