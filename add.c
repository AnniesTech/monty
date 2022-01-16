#include "monty.h"

/**
 * add - Function that adds the first two values
 * at the top of a double linked list
 *
 * @stack: doubly linked list
 * @line_number: line number not used
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n += (*stack)->n;
	pop(stack, line_number);
}
