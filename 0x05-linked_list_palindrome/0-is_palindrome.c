#include "lists.h"

/**
 * reverse - entry to reverse
 * Desc: reverse function that reverses a linked list
 * @node: double pointer listint_t type
 * Return: reversed node
 */
void reverse(listint_t **node)
{
	listint_t *prev = NULL;
	listint_t *current = *node;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*node = prev;
}

/**
 * compare_lists - entry to compare lists
 * Desc: compare_lists function that compares linked lists
 * @head_1: pointer listint_t type head
 * @head_2: pointer listint_t type reversed node
 * Return: 1 if they are the same, 0 if not
 */
int compare_lists(listint_t *head_1, listint_t *head_2)
{
	listint_t *temp1 = head_1;
	listint_t *temp2 = head_2;

	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return (0);
	}

	if (temp1 == NULL && temp2 == NULL)
		return (1);

	return (0);
}

/**
 * is_palindrome - entry to is palindrome
 * Desc: is_palindrome function checks is it's palindrom
 * @head: double pointer listint_t type
 * Return: 0 if it is not palindrome, 1 if it is palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow_ptr = *head, *fast_ptr = *head;
	listint_t *second_half, *prev_of_slow_ptr = *head;
	listint_t *midnode = NULL;
	int is;

	if (*head != NULL && (*head)->next != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			prev_of_slow_ptr = slow_ptr;
			slow_ptr = slow_ptr->next;
		}

		if (fast_ptr != NULL)
		{
			midnode = slow_ptr;
			slow_ptr = slow_ptr->next;
		}

		second_half = slow_ptr;
		prev_of_slow_ptr->next = NULL;
		reverse(&second_half);
		is = compare_lists(*head, second_half);

		reverse(&second_half);

		if (midnode != NULL)
		{
			prev_of_slow_ptr->next = midnode;
			midnode->next = second_half;
		}
		else
			prev_of_slow_ptr->next = second_half;
	}
	return (is);
}
