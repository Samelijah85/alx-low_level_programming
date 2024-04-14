#include "search_algos.h"
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, otherwise NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *skip;

	if (list == NULL)
	{
		return (NULL);
	}

	for (node = skip = list; skip->next != NULL && skip->n < value;)
	{
		node = skip;
		if (skip->express != NULL)
		{
			skip = skip->express;
			printf("Value checked at index [%ld] = [%d]\n",
					skip->index, skip->n);
		}
		else
		{
			while (skip->next != NULL)
			{
				skip = skip->next;
			}
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, skip->index);

	for (; node->index < skip->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
