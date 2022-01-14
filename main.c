#include "monty.h"

/**
 * _open - Function that opens a file
 * @argv: file
 * Return: the open file
 */

FILE *f_open(char *argv)
{
	FILE *file;

	file = fopen(argv, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	return (file);
}

int status = 0;

/**
 * main - main function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *str = NULL, *name = NULL, *value = NULL;
	int a = 0;
	FILE *file;
	stack_t *stack = NULL;
	size_t len = 0;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = f_open(argv[1]);

	while (getline(&str, &len, file) != -1)
	{
		name = strtok(str, " \t\n");

		if (!name || *name == ' ')
		{
			a++;
			continue;
		}

		value = strtok(NULL, " \t\n");
		start(&stack, name, value, a + 1);
		if (status == EXIT_FAILURE)
		{
			free(str);
			free_dlist(stack);
			fclose(file);
			exit(status);
		}
		a++;
	}
	free(str);
	fclose(file);
	free_dlist(stack);
	return (0);
}
