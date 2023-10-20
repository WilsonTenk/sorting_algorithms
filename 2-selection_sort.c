#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
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
 * selection_sort - Sorts array of integers in ascending order
 *                  using selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Output the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t u, j;

	if (array == NULL || size < 2)
		return;

	for (u = 0; u < size - 1; u++)
	{
		min = array + u;
		for (j = u + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + u) != min)
		{
			swap_ints(array + u, min);
			print_array(array, size);
		}
	}
}
