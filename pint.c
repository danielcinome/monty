#include "monty.h"

/**
* pint - prints the value at the top of the stack
* @h : head
* @line_number : line number
*/

void pint(stack_t **h, unsigned int line_number)
{
	stack_t *head;
	int a = 0;

	if (h == NULL || *h == NULL)
	{
		printf("L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = *h;
	a = head->n;
	printf("%d\n", a);
}
