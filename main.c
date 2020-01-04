#include "monty.h"

/**
 * main - principal function
 * @ac: Number of arguments
 * @av: arguments
 * Return: 0 or 1
 */
int number = 0;
int main(int ac, char **av)
{
	stack_t *head;
	char *buff;
	char **token, **word_cmp;
	int i = 0, j = 0, line_number = 0;
	instruction_t fun[] = {
		{"push", push},
		{"pint", pint},
		{NULL, NULL}
	};

	head = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(1);
	}
	buff = read_textfile(av[1]);
	token = tokens(buff, "\n");
	while (token[i] != NULL)
	{
		line_number++;
		word_cmp = tokens(token[i], " ");
		if (word_cmp[0] != NULL)
		{
			while (fun[j].opcode != NULL)
			{
				if (strcmp(word_cmp[0], "pall") == 0)
				{
					pall(head);
					break;
				}
				if (strcmp(fun[j].opcode, word_cmp[0]) == 0)
				{
					if (word_cmp[1] != NULL)
						number = _atoi(word_cmp[1], line_number);
					(fun[j].f)(&head, line_number);
				}
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (0);
}
