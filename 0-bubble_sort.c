#include "sort.h"

/**
 * swap_ints - This swaps the two integer array.
 * @w: First integer to be swap.
 * @t: Second integer to be swap.
 */
void swap_ints(int *w, int *t)
{
	int tmp;

	tmp = *w;
	*w = *t;
	*t = tmp;
}

/**
 * bubble_sort - should sort integer arrays in ascending order.
 * @array: Array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each of swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t u, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (u = 0; u < len - 1; u++)
		{
			if (array[u] > array[u + 1])
			{
				swap_ints(array + u, array + u + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
