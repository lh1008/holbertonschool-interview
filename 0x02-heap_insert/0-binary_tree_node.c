#include "binary_trees.h"

/**
 * binary_tree_node - entry function
 * Desc: binary_tree_node function that creates a binary tree
 * @parent: binary_tree_t type pointer to structure
 * @value: int value to put in the new node
 * Return: returns pointer to new node or NULL if failed
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);

}
