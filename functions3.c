#include "monty.h"

/**
* _mod - computes the rest of the division of the
* second top element of the stack by the top
* element of the stack.
* @stack : head
* @line_number : line number
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->n;
	if (mod == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n = ((*stack)->n) % (mod);
}
