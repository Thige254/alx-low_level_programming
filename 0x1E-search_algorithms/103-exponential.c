#include "search_algos.h"
#include <stdio.h>

/**
 * exponential_search - Searches for value in sorted array using Exponential
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where value is located,/-1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, min;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	min = (bound < size - 1) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, min);
	print_range(array, bound / 2, min);

	return (binary_search(array, bound / 2, min, value));
}

/**
 * binary_search - Searches for a value in a sorted array using Binary search
 * @array: Pointer to the first element of the array to search in
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if not present
 */
int binary_search(int *array, size_t start, size_t end, int value)
{
	size_t mid, i;

	while (start <= end)
	{
		printf("Searching in array: ");
		for (i = start; i < end; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = (start + end) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return (-1);
}

/**
 * print_range - Prints the elements of an array within a specified range
 * @array: Pointer to the first element of the array
 * @start: Starting index of the range
 * @end: Ending index of the range
 */
void print_range(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}
