#include "monty.h"

/**
 * start - Function that selects the function to execute it
 * @stack: linked list
 * @name: Name of the function
 * @value: The number in the file
 * @inf: The number of the line
 *
 * Return: nothing
 */

void start(stack_t **stack, char *name, char *value, int inf)
{
	int indx = 0;

	for (; instructions[indx].opcode; indx++)
	{
		if (strcmp(name, instructions[indx].opcode) == 0)
		{
			if (strcmp(name, instructions[0].opcode) != 0)
			{
				instructions[indx].f(stack, inf);
				return;
			}
			if (strcmp(name, instructions[0].opcode) == 0 && !_checknum(value))
			{
				status = EXIT_FAILURE;
				fprintf(stderr, "L%d: usage: push integer\n", inf);
				return;
			}
			if (strcmp(name, instructions[0].opcode) == 0 && !value)
			{
				status = EXIT_FAILURE;
				fprintf(stderr, "L%d: usage: push integer\n", inf);
				return;
			}
			instructions[indx].f(stack, atoi(value));
			return;
		}
	}
	status = EXIT_FAILURE;
	fprintf(stderr, "L%d: unknown instruction %s\n", inf, name);
}

/**
 * _checknum - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int _checknum(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[i] == '-')
	{
		i++;
	}
	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
