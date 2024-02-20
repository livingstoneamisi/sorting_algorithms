#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - uses selection sort algorithm to sort
 * an array of integers
 * @array: actual array.
 * @size: array size.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int min, i, j;
	int s = size;

	if (array == NULL || s < 2)
		return;

	for (i = 0; i < (s - 1); i++)
	{
		min = i;
		for (j = (i + 1); j < s; j++)
			min = (array[j] < array[min]) ? j : min;

		if (min != i)
		{
			swap_ints(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
