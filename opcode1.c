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

/**
 * nop - doesn’t do anything
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;
	stack_t *list = *stack;
	int elements = 0;
	int sub;

	while (list != NULL)
	{
		elements++;
		list = list->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = (*stack)->next;
	sub = top2->n - top1->n;

	free(top1);
	top2->n = sub;

	*stack = top2;
}



/**
 * divide - divides the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 */

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;
	stack_t *list = *stack;
	int elements = 0, div;

	while (list != NULL)
	{
		elements++;
		list = list->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = (*stack)->next;

	if (top1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = top2->n / top1->n;

	free(top1);
	top2->n = div;

	*stack = top2;
}


