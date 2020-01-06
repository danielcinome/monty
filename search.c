#include "monty.h"

/**
 * case_push - case push
 * @ops: function push
 * @word_cmp: word token
 * @line_number: number of line
 */
void case_push(instruction_t ops[], char **word_cmp, unsigned int line_number)
{
	int i = 0, j = 0;

	if (word_cmp[1] == NULL)
	{
		free(word_cmp);
		fprintf(stderr, "L%d: usage: push integer\n", line_number),
		exit(EXIT_FAILURE);
	}
	if (word_cmp[1][0] == '-')
		j++;
	while (word_cmp[1][j])
	{
		if (isdigit(word_cmp[1][j]) == 0)
		{
			free(word_cmp);
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	(ops[i].f)(&head_stack, _atoi(word_cmp[1]));
}

/**
* search - function that the opcode looks for
* @buff : line content
* @line_number : line number
*/

void search(char *buff, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", mul}, {"mod", _mod}, {"pchar", pchar},
		{"pstr", pstr}, {NULL, NULL}};

	char **word_cmp;
	int flag = 0, i = 0;

	word_cmp = tokens(buff, "\t ");
	if (word_cmp[0] == NULL || word_cmp[0][0] == '#')
	{
		free(word_cmp);
		return;
	}
	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, word_cmp[0]) == 0)
		{
			if (strcmp(word_cmp[0], "push") == 0)
			{
				case_push(ops, word_cmp, line_number);
			}
			else
			{
				(ops[i].f)(&head_stack, line_number);
			}
			flag = 1;
		}
		i++;
	}
	if (flag != 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, word_cmp[0]);
		exit(EXIT_FAILURE);
	}
	free(word_cmp);
}
