#include "monty.h"

stack_t *stack = NULL;
val_t value;

/**
 * main - entry point
 * @argc: arguments count
 * @args: arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **args)
{
	FILE *file;
	char *fname;
	//char line[BUFFER_LINE];
	//char *instruct;
	//int line_number;
	//char *nvalue;
	//void (*f)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fname = args[1];
	file = fopen(fname, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}

	processFile(file, stack);

	return (0);
}
