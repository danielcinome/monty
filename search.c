#include "monty.h"

/**
* search - function that the opcode looks for
* @buff : line content
* @line_number : line number
*/

void search(char *buff, unsigned int line_number)
{
	instruction_t ops[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};
	char **word_cmp;
	int i = 0, j = 0, flag = 0;

	word_cmp = tokens(buff, "\t ");
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, word_cmp[0]) == 0)
		{
			if (strcmp(word_cmp[0], "push") == 0)
			{
				if (word_cmp[1] == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number),
					exit(EXIT_FAILURE);
				}
				if (word_cmp[1][0] == '-')
					j++;
				while (word_cmp[1][j])
				{
					if (isdigit(word_cmp[1][j]) == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_number);
						exit(EXIT_FAILURE);
					}
					j++;
				}
				(ops[i].f)(&head_stack, _atoi(word_cmp[1]));
			}
			else
				(ops[i].f)(&head_stack, line_number);
			flag = 1;
		}
		i++;
	}
	if (flag != 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, word_cmp[0]);
		exit(EXIT_FAILURE);
	}
}
