#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;
	stack_t *list = *stack;
	int elements = 0;
	int sum;

	while (list != NULL)
	{
		elements++;
		list = list->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = (*stack)->next;
	sum = top1->n + top2->n;

	free(top1);
	top2->n = sum;

	*stack = top2;
}


