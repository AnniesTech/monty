#include "monty.h"

/**
 * free_dlist -  function that frees a double linked list.
 * @head:Main node
 */

void free_dlist(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
