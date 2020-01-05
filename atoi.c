#include "monty.h"

/**
* _atoi - funtion
* @s : pointer
* Return: int
*/

int _atoi(char *s)
{
	unsigned int val = 0;
	int c;
	int o = 1;

	for (c = 0; c[s] != '\0' ; c++)
	{
		if ((c[s] >= '0') && (c[s] <= '9'))
			val = ((val * 10) + (c[s] - '0'));

		else if (val != 0 && !((c[s] >= '0') && (c[s] <= '9')))
			break;

		else if (c[s] == '-')
			o = o * (-1);

		else
			val = val;
	}
	return (o * val);
}
