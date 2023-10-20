#include "sort.h"

void swap_ints(int *w, int *t);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap 2 integers in an array.
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
 * hoare_partition - Arrange subset of an array of integers
 *                   according to hoare partition scheme.
 * @array: Array of integers
 * @size: Size of the array.
 * @start: Starting index of subset to order
 * @end: Ending index of subset to order
 *
 * Return: Final partition index
 *
 * Description: Uses last element of the partition as the pivot.
 * Output the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int start, int end)
{
	int pivot, above, below;

	pivot = array[end];
	for (above = start - 1, below = end + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implmnt quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @start: Starting index of array partition to order.
 * @end: Ending index of array partition to order.
 *
 * Description: Use the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = hoare_partition(array, size, start, end);
		hoare_sort(array, size, start, part - 1);
		hoare_sort(array, size, part, end);
	}
}

/**
 * quick_sort_hoare - Sort array of integers in ascending
 *                    order using quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array
 *
 * Description: Use Hoare partition scheme. Prints
 * the array after swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
