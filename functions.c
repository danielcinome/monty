#include "monty.h"

/**
* push - adds a new node at the beginning of a stack
* @stack: head of list
* @line_number: number
* Return: new node
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *new;

	if (stack == NULL)
		exit(1);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	new->n = line_number;
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		temp->prev = new;
		*stack = new;
	}
}

/**
* pall -  prints all the values on the stack
* @stack : head
* @line_number : line number
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	temp = *stack;
	line_number = line_number;
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	*stack = temp;
}

/**
* pint - prints the value at the top of the stack
* @stack : head
* @line_number : line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	printf("%d\n", (*stack)->n);
}
