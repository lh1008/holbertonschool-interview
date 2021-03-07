#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/**
 * print_list - entry to print_list
 * Desc: print_list function prints the n int
 * @node: pointer to listint_t type
 * Return: print struct n
 */
void print_list(listint_t *node)
{
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

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

		if (is == 1)
			printf("Is palindrome\n");
		else
			printf("Is not palindrome\n");

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

/**
 * main - entry to main
 * Desc: main function
 * Return: 0
 */
int main(void)
{
	listint_t *head = NULL;
	listint_t *second = NULL;
	listint_t *third = NULL;
	listint_t *fourth = NULL;
	listint_t *fifth = NULL;
	listint_t *sixth = NULL;
	listint_t *seventh = NULL;
	listint_t *eighth = NULL;
	listint_t *nineth = NULL;
	listint_t *tenth = NULL;

	head = malloc(sizeof(listint_t));
	second = malloc(sizeof(listint_t));
	third = malloc(sizeof(listint_t));
	fourth = malloc(sizeof(listint_t));
	fifth = malloc(sizeof(listint_t));
	sixth = malloc(sizeof(listint_t));
	seventh = malloc(sizeof(listint_t));
	eighth = malloc(sizeof(listint_t));
	nineth = malloc(sizeof(listint_t));
	tenth = malloc(sizeof(listint_t));

	if (head == NULL)
		return (0);
	if (second == NULL)
		return (0);
	if (third == NULL)
		return (0);
	if (fourth == NULL)
		return (0);
	if (fifth == NULL)
		return (0);
	if (sixth == NULL)
		return (0);
	if (seventh == NULL)
		return (0);
	if (eighth == NULL)
		return (0);
	if (nineth == NULL)
		return (0);
	if (tenth == NULL)
	   return (0);

	head->n = 1;
	head->next = second;

	second->n = 17;
	second->next = third;

	third->n = 972;
	third->next = fourth;

	fourth->n = 50;
	fourth->next = fifth;

	fifth->n = 98;
	fifth->next = sixth;

	sixth->n = 98;
	sixth->next = seventh;

	seventh->n = 50;
	seventh->next = eighth;

	eighth->n = 972;
	eighth->next = nineth;

	nineth->n = 17;
	nineth->next = tenth;

	tenth->n = 1;
	tenth->next = NULL;

	print_list(head);
	is_palindrome(&head);
	free(head);
	free(second);
	free(third);
	free(fourth);
	free(fifth);
	free(sixth);
	free(seventh);
	free(eighth);
	free(nineth);
	free(tenth);

	return (0);
}
