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

/**
* pchar - prints the char at the top of the stack,
* followed by a new line
* @stack : head
* @line_number : line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	if (num < 32 || num > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%c\n", num);
	}
}
/**
* _pstr - prints the string starting at the
* top of the stack, followed by a new line
* @stack : head
* @line_number : line number
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int num = 0;

	UNUSED(line_number);
	temp = *stack;
	while (temp != NULL && (*stack)->n != 0)
	{
		num = temp->n;
		if (num > 0 && num <= 127)
			printf("%c", num);
		else
			break;
		temp = temp->next;
	}
	printf("\n");
}

/**
* add_dnodeint_end - adds a new node at the end of a list
* @head : head
* @n : number
*/

void add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp;
	stack_t *new;

	if (head == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);

	temp = *head;
	new->n = n;
	if (temp == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new->next = NULL;
		new->prev = temp;
		temp->next = new;
	}
}

/**
* rotl - rotates the stack to the top.
* @stack : head
* @line_number : line number
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	int val = 0;

	val = (*stack)->n;
	pop(stack, line_number);
	add_dnodeint_end(stack, val);
}
