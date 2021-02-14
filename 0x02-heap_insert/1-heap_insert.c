#include "binary_trees.h"

/**
 * heap_insert - entry to function
 * Desc: Function that inserts a value into a Max Binary Heap
 * @root: double pointer to heap_t struct type
 * @value: int value to node inserted
 * Return: pointer to inserted node and NULL if failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert_node = NULL;

	insert_node = malloc(sizeof(heap_t));

	insert_node->n = value;

	if (*root == 0)
	{
		insert_node  = *root;
		return (insert_node);
	} else if ((*root)->n == value)
	{
		return (insert_node);
	} else if ((*root)->n < value)
	{
		while ((*root)->n < value)
		{
			insert_node->left = *root;
			return (insert_node);
		}
	} else if ((*root)->n > value)
	{
		while ((*root)->n > value)
		{
			insert_node->right = *root;
			return (insert_node);
		}
	}
	return (insert_node);

}
