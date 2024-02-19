#include "sort.h"

int getmax(int arr[], int size);
void count_sort(int array[], int size, int exp);


/**
 * radix_sort - Radix sort algorithm.
 * Uses the LSD radix sort algorithm
 * @array: pointer to actual array
 * @size: pointer to array size
 *
 */
void radix_sort(int *array, size_t size)
{
	int m = getmax(array, size);
	int i;

	for (i = 1; m / i > 0; i *= 10)
	{
		count_sort(array, size, i);
		print_array(array, size);
	}
}

/**
 * getmax - finds the maximum value in the array
 * @arr: actual array
 * @size: array size
 *
 * Return: largest value
 */
int getmax(int arr[], int size)
{
	int a = arr[0], i;

	for (i = 0; i < size; i++)
	{
		if (arr[i] > a)
		{
			a = arr[i];
		}
	}
	return (a);
}

/**
 * count_sort - does the actual counting sort
 * @array: actual array
 * @size: array size
 * @exp: significant digit
 *
 */
void count_sort(int array[], int size, int exp)
{
	int *result = malloc(size * sizeof(int));
	int i, count[10] = {0};

	if (result == NULL)
	{
		free(result);
		return;
	}

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = (size - 1); i >= 0; i--)
	{
		result[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = result[i];
	}
	
	free(result);
}
