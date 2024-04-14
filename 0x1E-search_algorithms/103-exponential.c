#include "search_algos.h"

/**
 * print_array - Prints the elements of an array.
 * @array: Pointer to the first element of the array to print
 * @start: The first index to start printing from
 * @end: The last index to print
 */
void print_array(int *array, int start, int end)
{
	printf("Searching in array: ");
	for (; start <= end; start++)
	{
		printf("%d", array[start]);
		if (start == end)
		{
			printf("\n");
		}
		else
		{
			printf(", ");
		}
	}
}

/**
 * _binary_search - Searches for a value in a sorted array of integers using
 * the Binary search algorithm.
 * @array: Pointer to the first element of the array to search in
 * @value: Value to search for
 * @low: The lowest index to search
 * @high: The highest index to search
 *
 * Return: The index where value is located, otherwise -1
 */
int _binary_search(int *array, int value, size_t low, size_t high)
{
	size_t mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		print_array(array, low, high);
		if (value < array[mid])
		{
			high = mid - 1;
		}
		else if (value > array[mid])
		{
			low = mid + 1;
		}
		else
		{
			return ((int) mid);
		}
	}
	return (-1);
}

/**
 * min - Returns the minimum of 2 values
 * @a: First value
 * @b: Second value
 *
 * Return: The minimum of 2 values
*/
size_t min(size_t a, size_t b)
{
	return ((a < b) ? a : b);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located, otherwise -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	bound = 1;
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
	bound / 2, min(bound + 1, size) - 1);
	return (_binary_search(array, value, bound / 2, min(bound + 1, size) - 1));
}
