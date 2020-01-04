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

	line_number = line_number;
	if (stack == NULL)
		exit(1);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(1);

	temp = *stack;
	new->n = number;
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		printf("Entre 0\n");
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		temp->prev = new;
		*stack = new;
		printf("Entre n\n");
	}
	printf("%d\n", new->n);
}

void pall(stack_t **stack, unsigned int line_number)
{

	line_number = line_number;
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	printf("Hola\n");
}