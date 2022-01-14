#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Doubly linked list
 * @line_number: not used
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp = NULL;

	if (head == NULL)
	{
		printf("L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	temp = head;
	if (temp->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
	temp = NULL;
}
