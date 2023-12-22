#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - Searches for value in sorted array
 * using advanced binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not present
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left, right, mid;

	if (array == NULL)
		return (-1);

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (mid = left; mid < right; mid++)
			printf("%d, ", array[mid]);
		printf("%d\n", array[mid]);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
		{
			if (mid == left || array[mid - 1] != value)
				return (mid);
			right = mid;
		}
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	return (-1);
}
