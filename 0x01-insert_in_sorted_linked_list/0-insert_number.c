#include "lists.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node - Entry point
 * Desc: insert_node function
 * @head: pointer to listint_t
 * @number: const int
 * Return: Function that adds a new node or NULL if fails.
 **/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *actual;

	actual = *head;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = number;
	node->next = NULL;

	if (actual == NULL)
	{
		node->next = actual;
		*head = node;
		return (*head);
	}

	while (actual->next != NULL && actual->next->n < number)
	{
		actual = actual->next;
	}
	node->next = actual->next;
	actual->next = node;
	return (*head);
}
