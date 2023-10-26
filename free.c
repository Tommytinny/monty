#include "monty.h"

/**
 * free_stack - free all allocated memories
 * @stack: pointer to the head node pointer of stack
 * @line_number: the line_number in file
 *
 * Return: nothing
 */
void free_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *list = *stack;

	(void)line_number;

	while (list)
	{
		current = list;
		list = list->next;
		free(current);
	}
}
