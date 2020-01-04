#include "monty.h"

/**
* _atoi - funtion
* @s : pointer
* @line_number : line number
* Return: int
*/

int _atoi(char *s, int line_number)
{
	unsigned int val = 0;
	int c;
	int o = 1, a = 0;

	for (c = 0; c[s] != '\0' ; c++)
	{
		if ((c[s] >= '0') && (c[s] <= '9'))
			val = ((val * 10) + (c[s] - '0'));

		else if (val != 0 && !((c[s] >= '0') && (c[s] <= '9')))
			break;

		else if (c[s] == '-')
			o = o * (-1);

		else
			a = 1;
	}
	if (a == 1)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (o * val);
}
