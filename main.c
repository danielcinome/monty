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
	 stack_t *head = NULL;
	char *line_buff = NULL;
	size_t line_buff_size = 0;
	unsigned int line_number = 1;
	char *tok;
	FILE *fp = fopen(av[1], "r");

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line_buff, &line_buff_size, fp) >= 0)
	{
		tok = strtok(line_buff, "\n\t\r");
		if (tok != NULL)
			search(tok, line_number, &head);
		line_number++;
	}
	free(line_buff);
	line_buff = NULL;
	fclose(fp);
	printf("%d\n", line_number);
	return (0);
	/*
	buff = read_textfile(av[1]);
	token = tokens(buff, "\n");
	while (token[i] != NULL)
	{
		word_cmp = tokens(token[i], " ");
		if (token[0] == NULL)
			line_number++;
		if (word_cmp[0] != NULL)
		{
			while (fun[j].opcode != NULL)
			{
				if (strcmp(fun[j].opcode, word_cmp[0]) == 0)
				{
					if (word_cmp[1] != NULL)
						number = _atoi(word_cmp[1], line_number);
					(fun[j].f)(&head, line_number);
				}
				j++;
			}
			line_number++;
		}
		i++;
		j = 0;
	}
	*/
}
