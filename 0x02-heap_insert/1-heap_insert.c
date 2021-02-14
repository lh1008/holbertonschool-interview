#include "binary_trees.h"

/**
 * heap_insert - entry point from main
 * Desc: heap_insert function that inserts value with Max Binary Heap
 * @root: heap_t type double pointer to root
 * @value: int type value to insert to new node
 * Return: a pointer to the new node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	heap_t *parent;

	if (root == NULL)
		return (NULL);

	parent = find_parent(*root);
	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	if (parent == NULL)
		*root = new_node;
	else if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	sort_nodes(&new_node);

	return (new_node);
}

/**
 * sort_nodes - entry point
 * Desc: sort_nodes function that sorts a child and parent
 * @node: heap_t type inserted node
 * Return: voind function
*/
void sort_nodes(heap_t **node)
{
	heap_t *current;
	int n;

	current = *node;

	while (current->parent != NULL)
	{
		if (current->parent->n < current->n)
		{
			n = current->parent->n;
			current->parent->n = current->n;
			current->n = n;
			*node = current->parent;
		}
		current = current->parent;
	}
}

/**
 * perfect_tree - entry point
 * Desc: perfect_tree function that validates if the tree is perfect
 * @root: pointer to the root
 * Return: 1 for true, otherwhise 0
*/
int perfect_tree(const heap_t *root)
{
	int left, right;

	if (root == NULL)
		return (0);

	left = nodes(root->left);
	right = nodes(root->right);

	if (left == right)
		return (1);

	return (0);
}

/**
 * nodes - entry point
 * Desc: nodes function that counts the left and right nodes
 * @root: double pointer to the root
 * Return: number of nodes
*/
int nodes(heap_t *root)
{
	int left;

	if (root == NULL)
		return (0);

	if (root)
		left = 1;

	left += nodes(root->left);
	left += nodes(root->right);

	return (left);
}

/**
 * find_parent - entry point
 * Desc: find_parent to find parent to insert child
 * @root: heap_t type double pointer
 * Return: Pointer to the parent
*/
heap_t *find_parent(heap_t *root)
{
	heap_t *parent;
	int left, right, left_l, right_l;

	if (root == NULL)
		return (NULL);

	parent = root;
	left = nodes(parent->left);
	right = nodes(parent->right);
	left_l = perfect_tree(parent->left);
	right_l = perfect_tree(parent->right);

	if (left < 1 || right < 1)
		return (parent);

	if (left_l < 1 || (left_l && right_l && left == right))
		return (find_parent(parent->left));
	else if (right_l < 1 || (left_l && right_l && left > right))
		return (find_parent(parent->right));

	return (parent);
}
