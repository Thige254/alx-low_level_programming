#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search value in a sorted array using a jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int jump_search(int *arr, size_t sz, int val)
{
	size_t step, start = 0, end = 0;

	if (!arr)
		return (-1);

	step = (size_t)sqrt(sz);
	while (end < sz && arr[end] < val)
	{
		printf("Value checked arr[%d] = [%d]\n", (int)end, arr[end]);
		start = end;
		end += step;

		if (start >= sz)
			return (-1);
	}

	printf("Value found between indexes [%d] and [%d]\n", (int)start, (int)end);

	end = (end >= sz) ? sz - 1 : end;

	for (; (start <= end) && (arr[start] <= val); start++)
	{
		printf("Value checked arr[%d] = [%d]\n", (int)start, arr[start]);
		if (arr[start] == val)
			return ((int)start);
	}

	return (-1); /* Value not found */
}
