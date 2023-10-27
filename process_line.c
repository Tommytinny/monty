#include "monty.h"

/**
 * get_opcode_func - Entry to the function
 * @s: a pointer to the string
 * @line: position of lines
 *
 * Return: Nothing
 */

void (*get_opcode_func(char *s, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i = 0;

	while (instruct[i].opcode != NULL && strcmp(instruct[i].opcode, s) != 0)
		i++;

	if (instruct[i].f == NULL)
		error(s, line);
	return (instruct[i].f);
}
