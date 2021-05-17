#include "search.h"

/**
 * print_found - entry to print_found
 * Desc: print_found function to print message when limits are found
 * @index1: from this index
 * @index2: to this index
 * @last: know if the last one in express line
 * Return: nothing
 */
void print_found(size_t index1, size_t index2, skiplist_t *last)
{
	if (last != NULL)
	{
		while (last->next != NULL)
			last = last->next;
		index2 = last->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", index1, index2);
}

/**
 * print_check - entry to print check
 * Desc: print_check function to print message when values are checked
 * @index: index where is comparing
 * @value: value to compare
 * Return: nothing
 */
void print_check(size_t index, int value)
{
	printf("Value checked at index [%lu] = [%i]\n", index, value);
}

/**
 * normal_lane - entry to find one by one
 * Desc: normal_lane function that checks next by next normal lane
 * @list: express line node
 * @value: value to compare
 * Return: node found
 */
skiplist_t *normal_lane(skiplist_t *list, int value)
{
	skiplist_t *node_list = list;

	if (list == NULL)
		printf("n head nullll");
	for (; node_list; node_list = node_list->next)
	{
		print_check(node_list->index, node_list->n);
		if (node_list->n == value)
			return (node_list);
	}

	return (NULL);
}

/**
 * linear_skip - entry to linear skip
 * Desc: linear_skip function that searches for
 * a value in a sorted skip list of integers
 * @list: structure pointer to head of the skip list
 * @value: value to search
 * Return: NULL if value not present or head list NULL or value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current  = list, *next = NULL;

	if (list == NULL)
		return (NULL);

	while (current != NULL)
	{
		next = current->express;
		if (next != NULL)
		{
			print_check(next->index, next->n);
			if (next->n >= value)
			{
				print_found(current->index, next->index, NULL);
				return (normal_lane(current, value));
			}

			if (next->express == NULL)
			{
				print_found(next->index, 0, next);
				return (normal_lane(next, value));
			}
		}

		current = current->express;
	}

	return (NULL);
}
