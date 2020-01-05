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

/**
* sub - subtracts the top element of the stack
* from the second top element of the stack
* @stack : head
* @line_number : line number
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n - sub;
}

/**
* _div - divides the second top element of the stack
* by the top element of the stack
* @stack : head
* @line_number : line number
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->n;
	if (div == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n = ((*stack)->n) / (div);
}
