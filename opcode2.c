#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 *
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;
	stack_t *list = *stack;
	int elements = 0, mul;

	while (list != NULL)
	{
		elements++;
		list = list->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = (*stack)->next;

	mul = top2->n * top1->n;

	free(top1);
	top2->n = mul;

	*stack = top2;
}

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;
	stack_t *list = *stack;
	int elements = 0, mod;

	while (list != NULL)
	{
		elements++;
		list = list->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = (*stack)->next;

	if (top1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = top2->n % top1->n;

	free(top1);
	top2->n = mod;

	*stack = top2;
}


