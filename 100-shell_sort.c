#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @w: First integer to swap.
 * @t: Second integer to swap.
 */
void swap_ints(int *w, int *t)
{
	int tmp;

	tmp = *w;
	*w = *t;
	*t = tmp;
}

/**
 * shell_sort - Sort array of integers in ascending
 *              order by the shell sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Use Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, u, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (u = gap; u < size; u++)
		{
			j = u;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
