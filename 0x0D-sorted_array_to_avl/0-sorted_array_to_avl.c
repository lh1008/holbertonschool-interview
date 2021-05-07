#include "binary_trees.h"

/**
 * new_node - entry to new node
 * Desc: new_node function that creates a new AVL node
 * @parent: avl_t AVL struct
 * @n: size_t type where to start
 * Return: return new node
 */
avl_t *new_node(avl_t *parent, size_t n)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (node == NULL && parent == NULL)
		return (NULL);

	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * sort_data - entry to sort data
 * Desc: Function that sorts the AVL tree
 * @array: int array pointer to numbers
 * @start: size_t type where to size of the array starts
 * @end: size_t type where the size of the arrray ends
 * @parent: AVL tree
 * Return: returns root sorted
 */
avl_t *sort_data(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t middle_element;
	avl_t *root;

	if (start > end)
		return (NULL);

	middle_element = (start + end) / 2;

	root = new_node(parent, array[middle_element]);

	if (start != middle_element)
		root->left = sort_data(array, start, middle_element - 1, root);

	if (end != middle_element)
		root->right = sort_data(array, middle_element + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - entry to function sorted array to avl
 * Desc: sorted_array_to_avl function that builds an AVL tree from an array
 * @array: int type pointer to array of numbers
 * @size: size_t type size of the array
 * Return: pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size < 1)
		return (NULL);

	root = sort_data(array, 0, size - 1, NULL);

	return (root);
}
