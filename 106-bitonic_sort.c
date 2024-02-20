#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge function for bitonic merge
 * @array: Array to be merged
 * @size: Size of the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t half = size / 2;
        size_t i;

        printf("Merging [%lu/%lu] (%s):\n", size, size, (dir == 1) ? "UP" : "DOWN");
        print_array(array, size);

        bitonic_merge(array, half, 1);
        bitonic_merge(array + half, half, 0);

        bitonic_sort_merge(array, size, dir);
        
        printf("Result [%lu/%lu] (%s):\n", size, size, (dir == 1) ? "UP" : "DOWN");
        print_array(array, size);
    }
}

/**
 * bitonic_sort - Bitonic sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (size > 1)
    {
        printf("\n");
        bitonic_merge(array, size, 1);
    }
}

