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
		if (start < end)
		{
			printf(", ");
		}
	}
	printf("\n");
}

/**
 * binary_search - Searches for a value in a sorted array of integers using
 * the Binary search algorithm.
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where value is located, otherwise -1
 */
int binary_search(int *array, size_t size, int value)
{
	int mid;
	int left = 0;
	int right = (int) size - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		print_array(array, left, right);
		if (value < array[mid])
		{
			right = mid - 1;
		}
		else if (value > array[mid])
		{
			left = mid + 1;
		}
		else
		{
			return (mid);
		}
	}
	return (-1);
}
