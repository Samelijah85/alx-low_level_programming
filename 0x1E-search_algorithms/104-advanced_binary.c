#include "search_algos.h"

/**
  * binary_search_recursive - Searches recursively for a value in a sorted
  * array of integers using binary search.
  * @array: A pointer to the first element of the [sub]array to search.
  * @low: The starting index of the [sub]array to search.
  * @high: The ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: The index where value is located, otherwise -1
  */
int binary_search_recursive(int *array, size_t low, size_t high, int value)
{
	size_t i;

	if (high < low)
		return (-1);

	printf("Searching in array: ");
	for (i = low; i < high; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = low + (high - low) / 2;
	if (array[i] == value && (i == low || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (binary_search_recursive(array, low, i, value));
	return (binary_search_recursive(array, i + 1, high, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located, otherwise -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1);
	}

	return (binary_search_recursive(array, 0, size - 1, value));
}
