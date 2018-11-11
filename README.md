Sorting algorithms

This repository contains implementation of famous sorting algorithms as well as a benchmark program to see how efficient they are.

Currently, the following algorithms available:
* Bubble
* Insertion
* Merge
* Heap

Each implementation works with uint32_t type (TODO: make it more generic).

Building

In order to build executable benchmark and all sorting algorithms the following command should be used:

\# make

The above, will run a benchmark on array of 1000 uint32 integeres. This is too low for modern PCs therefore you will see 0ms for most sorting implementations.

-DARRAY_SIZE=1000000 should be used to run benchmark on 1 million integers array:

\# make CFLAGS="-DARRAY_SIZE=1000000"

Bubble and Insertion sorts would probably not be relevant for arrays of size 1 million hence it make sense to drop them off the benchmark:

\# make CFLAGS="-DARRAY_SIZE=1000000 -DSKIP_BUBBLE_SORT -DSKIP_INSERTION_SORT"
