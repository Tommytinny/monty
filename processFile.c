#include "monty.h"

/**
 * error - function to display and exit if encounter
 * unknown instruction
 * @instruct: insruction read from line
 * @line_number: the line number of lines
 *
 * Return: Nothing
 */

void error(char *instruct, int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruct);
	exit(EXIT_FAILURE);
}

/**
 * printUsageError - function to display and exit if encounter
 * unknown instruction
 * @line_number: the line number of lines
 * @instruct: insruction read from line
 */
void printUsageError(int line_number, char *instruct)
{
	fprintf(stderr, "L%d: usage: %s integer\n", line_number, instruct);
	exit(EXIT_FAILURE);
}

/**
 * processFile - function that processes lines in the file
 * @file: file with the lines to be read
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing
 */

void processFile(FILE *file, stack_t *stack)
{
	char line[BUFFER_LINE], *instruct, *nvalue, *endptr;
	int line_number = 1, val;
	size_t pos;
	void (*f)(stack_t **, unsigned int);

	while (fgets(line, sizeof(line), file) != NULL)
	{
		instruct = strtok(line, " \n");
		nvalue = strtok(NULL, " \n");
		if (instruct == NULL)
		{
			line_number++;
			continue;
		}
		if (nvalue == NULL)
		{
			if (strcmp(instruct, "push") == 0)
				printUsageError(line_number, instruct);
			pos = strcspn(instruct, "\n");
			instruct[pos] = '\0';
			get_opcode_func(instruct, line_number)(&stack, line_number);
		}
		else
		{
			val = atoi(nvalue);
			f = get_opcode_func(instruct, line_number);
			if (strcmp(instruct, "push") == 0)
			{
				strtol(nvalue, &endptr, 10);
				if (nvalue == NULL || *endptr != '\0')
					printUsageError(line_number, instruct);
				f(&stack, val);
			}
			else
				f(&stack, line_number);
		}
		line_number++;
	}
	free_stack(&stack, 0);
	fclose(file);
}
