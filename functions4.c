#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack : head
 * @line_number : line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	int val = 0;

	UNUSED(line_number);
	if ((*stack) != NULL && (*stack)->next != NULL)
	{
		while ((*stack)->next != NULL)
		{
			*stack = (*stack)->next;
		}
		val = (*stack)->n;
		while ((*stack)->prev != NULL)
		{
			(*stack)->n = (*stack)->prev->n;
			*stack = (*stack)->prev;
		}
		(*stack)->n = val;
	}
}
