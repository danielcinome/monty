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
		exit(1);

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
