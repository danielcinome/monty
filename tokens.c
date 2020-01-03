#include "monty.h"

/**
* tokens - separe the words of buffer
* @buff: words to separate
* @sep: character with separate the string
* Return: array with the separated words
*/
char **tokens(char *buff, char *sep)
{
	char *word;
	char **token;
	int i, val = 0;

	val = strlen(buff);
	token = malloc(sizeof(char *) * val);
	if (token == NULL)
		exit(1);
	word = strtok(buff, sep);
	for (i = 0; word != NULL; i++)
	{
		token[i] = word;
		word = strtok(NULL, sep);
	}
	token[i] = NULL;
	return (token);
}
