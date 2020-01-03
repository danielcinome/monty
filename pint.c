#include "monty.h"

void pint(stack_t **h, unsigned int line_number)
{
	stack_t *head;
	int a = 0;

	if (h == NULL || *h == NULL)
	{
		printf("L<%d>: unknown instruction <opcode>\n", line_number);
		exit (EXIT_FAILURE);
	}
	head = *h;
	a = head->n;
	printf("%d\n", a);
}
