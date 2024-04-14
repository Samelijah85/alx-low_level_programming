#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of integers using
 * the Linear search algorithm.
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where value is located, otherwise -1
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	for (i = 0; i < (int) size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (value == array[i])
		{
			return (i);
		}
	}
	return (-1);
}
