#include "monty.h"

/**
 * get_opcode_func - Entry to the function
 * @s: a pointer to the string
 *
 * Return: Nothing
 */

void (*get_opcode_func(char *s))(stack_t **, unsigned int)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i = 0;

	while (instruct[i].opcode != NULL && strcmp(instruct[i].opcode, s) != 0)
		i++;

	return (instruct[i].f);
}
