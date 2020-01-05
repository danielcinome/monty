#include "monty.h"

/**
* nop - go ahead
* @stack : head
* @line_number : line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
* add - adds the top two elements of the stack
* @stack : head
* @line_number : line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n + sum;
}
