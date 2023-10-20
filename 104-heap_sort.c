#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap integers in an array.
 * @w: First integer to swap
 * @t: Second integer to swap
 */
void swap_ints(int *w, int *t)
{
	int tmp;

	tmp = *w;
	*w = *t;
	*t = tmp;
}

/**
 * max_heapify - Change a binary tree into a complete binary heap.
 * @array: Array of integers representing a binary tree.
 * @size: Size of the array/tree.
 * @base: Index of the base row of the tree.
 * @root: Root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Array of integers in ascending
 *             order using heap sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Implmnts the sift-down heap sort
 * algorithm. Output the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int u;

	if (array == NULL || size < 2)
		return;

	for (u = (size / 2) - 1; u >= 0; u--)
		max_heapify(array, size, size, u);

	for (u = size - 1; u > 0; u--)
	{
		swap_ints(array, array + u);
		print_array(array, size);
		max_heapify(array, size, u, 0);
	}
}
