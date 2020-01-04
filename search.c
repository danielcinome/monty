#include "monty.h"

/**
 * 
 */
void search(char *buff, unsigned int line_number, stack_t **head)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    char **word_cmp;
    int i = 0;

    line_number = line_number;
    word_cmp = tokens(buff, "\t ");
    if (word_cmp[0] == NULL)
        return;
    while (ops[i].opcode != NULL)
    {
        if (strcmp(ops[i].opcode, word_cmp[0]) == 0)
        {
            if (word_cmp[1] != NULL)
						number = _atoi(word_cmp[1], line_number);
					(ops[i].f)(head, line_number);
        }
        i++;
    }
}