#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search for value in a sorted array using a jump search alg.
 * @arr: Pointer to the first element of the array to search in.
 * @sz: Number of elements in the array.
 * @val: The value to search for.
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
		printf("Value checked arr[%lu] = [%d]\n", end, arr[end]);
		start = end;
		end += step;

		if (start >= sz)
			return (-1);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", start, end);

	end = (end >= sz) ? sz - 1 : end;

	for (; (start <= end) && (arr[start] <= val); start++)
	{
		printf("Value checked arr[%lu] = [%d]\n", start, arr[start]);
		if (arr[start] == val)
			return ((int)start);
	}

	return (-1); /* Value not found */
}
