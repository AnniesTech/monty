#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Doubly linked list
 * @line_number: not used
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}
