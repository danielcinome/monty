#include "monty.h"

/**
 * free_stack - free of the list
 * @stack: Head of stack
 */
void free_stack(stack_t **stack)
{
	stack_t *aux;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		aux->prev = NULL;
		*stack = aux;
	}
	free(*stack);
}
