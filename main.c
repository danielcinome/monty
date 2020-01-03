#include "monty.h"

/**
 * main - principal function
 * @ac: Number of arguments
 * @av: arguments
 * Return: 0 or 1
 */
int main(int ac, char **av)
{
	stack_t *head;
	char *buff;
	char **token, **word_cmp;
	int i = 0, j = 0;
	instruction_t fun[] = {
		{"push", push},
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
		word_cmp = tokens(token[i], " ");
		while (fun[j].opcode != NULL)
		{
			if (strcmp(word_cmp[0], "pall") == 0)
				pall(head);
			if (strcmp(fun[j].opcode, word_cmp[0]) == 0)
			{
				(fun[j].f)(&head, atoi(word_cmp[1]));
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
