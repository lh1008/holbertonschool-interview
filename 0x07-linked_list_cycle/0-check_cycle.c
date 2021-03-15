#include "lists.h"

/**
 * check_cycle - entry to check cycle
 * Desc: check_cycle function that checks is a singly list has a cycle
 * @list: listint_t data struct singly list to be parsed
 * Return: 0 if there's no cycle and 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = NULL, *fast = NULL;

	if (list == NULL)
		return (0);

	slow = fast = list;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return (1);
		}
	}
	return (0);
}
