#include "list.h"

/**
 * add_node_end - entry to add node end
 * Desc: add_node_end function that adds a new node
 * to the end of a double circular linked list
 * @list: double pointer to List struct
 * @str: char type string to copy to new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last;

	if (*list == NULL)
	{
		new_node = malloc(sizeof(List));
		if (!new_node)
			return (NULL);
		new_node->str = str;
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = str;

	new_node->next = *list;
	(*list)->prev = new_node;
	new_node->prev = last;
	last->next = new_node;
	return (new_node);

}

/**
 * add_node_begin - entry to add node begin
 * Desc: add_node_begin function that adds a new node
 * to the beginning of a double circular linked list
 * @list: double pointer to List struct
 * @str: char type string to modify
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *last, *new_node;

	if (*list == NULL)
	{
		new_node = malloc(sizeof(List));
		if (!new_node)
			return (NULL);
		new_node->str = str;
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = malloc(sizeof(List));

	last = (*list)->prev;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = str;

	new_node->next = *list;
	new_node->prev = last;

	last->next = (*list)->prev = new_node;

	*list = new_node;

	return (new_node);
}
