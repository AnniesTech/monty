#include "monty.h"

/**
 * pall - print a doubly linked list
 *
 * @stack: double linked list
 * @line_number: not used
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	print_dlistint(*stack);
}
