#include "monty.h"

/**
 * push - push a node at the begining of stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int nval = line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = nval;
	new->next = *stack;
	*stack = new;
}

/**
 * pall - prints all values on the stack from top
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *list = *stack;

	(void)line_number;

	while (list != NULL)
	{
		if (list != NULL)
			fprintf(stdout, "%d\n", list->n);
		list = list->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *list = *stack;
	int i = 1;

	if (list == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (i == 1)
	{
		fprintf(stdout, "%d\n", list->n);
		i++;
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *list = *stack;
	stack_t *current;
	stack_t *h;

	if (list == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	h = current->next;
	free(current);

	*stack = h;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer of stack
 * @line_number: line number in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;
	stack_t *list = *stack;
	int elements = 0;

	while (list != NULL)
	{
		elements++;
		list = list->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = (*stack)->next;

	top1->next = top2->next;
	top2->next = top1;

	*stack = top2;
}


