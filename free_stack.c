#include "monty.h"

void free_stack(stack_t **stack)
{
    stack_t *aux;

    while (*stack)
    {
        aux = (*stack)->next;
        free(*stack);
        aux->prev = NULL;
        *stack = aux;
    }
    free(*stack);
}