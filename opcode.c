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
	int nval = value.val;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);

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
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	current = list;
	h = current->next;

	free(current);
	list = h;
}
