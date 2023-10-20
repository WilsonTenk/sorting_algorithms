#include "sort.h"

/**
 * get_max - Maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Th siize of the array.
 *
 * Return: Maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, u;

	for (max = array[0], u = 1; u < size; u++)
	{
		if (array[u] > max)
			max = array[u];
	}

	return (max);
}

/**
 * counting_sort - Sort the array of integers in ascending order
 *                 using counting sort algorithm.
 * @array: Array of integers.
 * @size: The siize of the array.
 *
 * Description: Output counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (u = 0; u < (max + 1); u++)
		count[u] = 0;
	for (u = 0; u < (int)size; u++)
		count[array[u]] += 1;
	for (u = 0; u < (max + 1); u++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; u < (int)size; u++)
	{
		sorted[count[array[u]] - 1] = array[u];
		count[array[u]] -= 1;
	}

	for (i = 0; u < (int)size; u++)
		array[u] = sorted[u];

	free(sorted);
	free(count);
}
