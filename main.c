#include "monty.h"
stack_t *head_stack = NULL;

/**
 * main - principal function
 * @ac: Number of arguments
 * @av: arguments
 * Return: 0 or 1
 */
int main(int ac, char **av)
{
	char *line_buff = NULL;
	size_t line_buff_size = 0;
	unsigned int line_number = 1;
	char *tok;
	FILE *fp = fopen(av[1], "r");

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
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
			search(tok, line_number);
		line_number++;
	}
	fclose(fp);
	free(line_buff);
	free_stack(head_stack);
	line_buff = NULL;
	return (0);
}
