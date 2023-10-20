#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subar: Sub-array of array of integers to sort.
 * @buff: Buffer to store sorted sub-array.
 * @front: Front index of the array.
 * @mid: Mmiddle index of the array.
 * @back: Back index of the array.
 */
void merge_subarr(int *subar, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t u, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subar + front, mid - front);

	printf("[right]: ");
	print_array(subar + mid, back - mid);

	for (u = front, j = mid; u < mid && j < back; k++)
		buff[k] = (subar[u] < subar[j]) ? subar[u++] : subar[j++];
	for (; u < mid; u++)
		buff[k++] = subar[u];
	for (; j < back; j++)
		buff[k++] = subar[j];
	for (u = front, k = 0; u < back; u++)
		subar[u] = buff[k++];

	printf("[Done]: ");
	print_array(subar + front, back - front);
}

/**
 * merge_sort_recursive - Implmt the merge sort algorithm through recursion.
 * @subar: Sub-array of an array of integers to sort.
 * @buff: Buffer store the sorted result.
 * @front: Front index of the sub-array.
 * @back: Back index of the sub-array.
 */
void merge_sort_recursive(int *subar, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subar, buff, front, mid);
		merge_sort_recursive(subar, buff, mid, back);
		merge_subarr(subar, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort array of integers in ascending
 *              order using merge sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Implmnts the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
