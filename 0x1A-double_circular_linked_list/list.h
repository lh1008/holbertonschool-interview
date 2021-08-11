#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/* New node function of a double circular linked list */
List *add_node_end(List **list, char *str);

/* New node to the beginning of a double circular linked list */
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
