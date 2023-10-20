#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @w: The first integer to swap.
 * @t: The second integer to swap.
 */
void swap_ints(int *w, int *t)
{
	int tmp;

	tmp = *w;
	*w = *t;
	*t = tmp;
}

/**
 * lomuto_partition - Order an array of integers according to
 *                    the lomuto partition scheme
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the subset to order.
 * @end: Ending index of the subset to order.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @start: Starting index of the array partition to order.
 * @end: Ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = lomuto_partition(array, size, start, end);
		lomuto_sort(array, size, start, part - 1);
		lomuto_sort(array, size, part + 1, end);
	}
}

/**
 * quick_sort - Sort integers in ascending
 *              order the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Uses Lomuto partition scheme. output
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
