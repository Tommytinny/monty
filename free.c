#include "monty.h"

/**
 * free - free all allocated memories
 *
 * Return: nothing
 */
void free_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *list = *stack;

	(void)line_number;

	while (list != NULL)
	{
		current = list;
		list = current->next;
		free(current);
	}
}
