#ifndef ARRAY_LIB_H
#define ARRAY_LIB_H

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

void fill_array(uint32_t[], size_t);
void print_array(uint32_t[], size_t);
bool is_sorted(uint32_t[], size_t);

#endif // ARRAY_LIB_H
