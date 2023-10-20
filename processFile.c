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
 * processFile - function that processes lines in the file
 * @file: file with the lines to be read
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing
 */

void processFile(FILE *file, stack_t *stack)
{
	char line[BUFFER_LINE], *instruct, *nvalue;
	int line_number, val;
	size_t pos;
	void (*f)(stack_t **, unsigned int);

	line_number = 1;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		instruct = strtok(line, " \n");
		nvalue = strtok(NULL, " \n");
		if (nvalue == NULL)
		{
			pos = strcspn(instruct, "\n");
			instruct[pos] = '\0';
			f = get_opcode_func(instruct);
			if (f == NULL)
				error(instruct, line_number);
			f(&stack, line_number);
		}
		else
		{
			val = atoi(nvalue);
			f = get_opcode_func(instruct);
			if (f == NULL)
				error(instruct, line_number);
			if (strcmp(instruct, "push") == 0)
			{
				if (val == 0 || nvalue[0] == '0')
				{
					fprintf(stderr, "L%d: usage: %s integer\n", line_number, instruct);
					exit(EXIT_FAILURE);
				}
				f(&stack, val);
			}
			else
				f(&stack, line_number);
		}
		line_number++;
	}
	fclose(file);
}
