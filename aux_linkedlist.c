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

/**
 * print_dlistint - Function that prints a double linked list
 * @h: Main node
 * Return: size of h
 */

size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;

	if (h != NULL)
	{
		while (h != NULL)
		{
			printf("%d\n", h->n);
			i++;
			h = h->next;
		}
	}
	return (i);
}
