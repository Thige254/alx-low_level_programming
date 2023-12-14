#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array using \
 * an interpolation search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, pos = 0;
	double ratio;

	if (!array)
		return (-1);

	while (array[high] != array[low])
	{
		ratio = (double)(high - low) / (array[high] - array[low]);
		pos = low + (ratio * (value - array[low]));

		if (pos >= size)
		{
			printf("Value checked array[%d] is out of range\n", (int)pos);
			break;
		}

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return ((int)pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return (value == array[low] ? (int)low : -1);
}
