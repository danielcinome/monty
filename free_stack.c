#include "monty.h"

/**
 * free_stack - free of the list
 * @stack: Head of stack
 */
void free_stack(stack_t *stack)
{
	while (stack)
	{
		stack = stack->next;
		free(stack);
		stack->prev = NULL;
	}
	free(stack);
}
