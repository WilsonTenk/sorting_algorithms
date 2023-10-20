/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - Sort a bitonic sequence inside array of integers
 * @array: Array of integers
 * @size: Size of the array.
 * @start: Starting index of sequence in array to sort.
 * @seq: Size of sequence to sort.
 * @flow: Direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t u, jump = seq / 2;

	if (seq > 1)
	{
		for (u = start; u < start + jump; u++)
		{
			if ((flow == UP && array[u] > array[u + jump]) ||
			    (flow == DOWN && array[u] < array[u + jump]))
				swap_ints(array + u, array + u + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Change array of integers into bitonic sequence.
 * @array: Array of integers
 * @size: Size of the array
 * @start: Starting index of block building bitonic sequence.
 * @seq: Size of a block building bitonic sequence.
 * @flow: Direction to sort bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort array of integers in ascending
 *                order using bitonic sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Output array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
