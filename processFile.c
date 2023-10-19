#include "monty.h"

/**
 * processFile - function that processes lines in the file
 * @file: file with the lines to be read
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing
 */

void processFile(FILE *file, stack_t *stack)
{
	char line[BUFFER_LINE];
	char *instruct;
	int line_number;
	char *nvalue;
	void (*f)(stack_t **, unsigned int);


	line_number = 1;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		instruct = strtok(line, " ");
		nvalue = strtok(NULL, " ");
		if (nvalue == NULL)
		{
			size_t pos = strcspn(instruct,"\n");
			instruct[pos] = '\0';
			f = get_opcode_func(instruct);

			if (f == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruct);
			}
			else
			{
				f(&stack, line_number);
			}
		}
		else
		{
			value.val = atoi(nvalue);
			
			f = get_opcode_func(instruct);
			if (f == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruct);
			}

			f(&stack, line_number);
		}

		line_number++;
		
	}


	fclose(file);
}
