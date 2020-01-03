#include "monty.h"

/**
 * pall - prints each element of the stack
 * @h: head of stack
 * Return: Always i
 */
size_t pall(const stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
