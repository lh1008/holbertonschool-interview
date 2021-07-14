#include "lists.h"

/**
 * find_listint_loop - entry to find listint loop
 * Desc: find_listint_loop function that finds the
 * loop in a linked list.
 * @head: pointer to node structure
 * Return: the address of the node where the loop
 * starts, or NULL if there's no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
		return (NULL);

	slow = fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow && fast)
			{
				if (slow == fast)
					return (slow);
				slow = slow->next;
				fast = fast->next;
			}
		}
	}
	return (NULL);
}
