#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of file
 * @letters: is the number of letters it should read and print
 * Return: actual number of letters it could read and print
 */
char *read_textfile(const char *filename)
{
	int fd, sav1;
	char *buff;

	buff = malloc(1024);
	if (filename == NULL)
	{
		printf("Error: malloc failed,\n");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(1);
	}
	sav1 = read(fd, buff, 1024);
	if (sav1 == -1)
		exit(1);
	close(fd);
	return (buff);
}
char **tokens(char *buff, char *sep)
{
	char *word;
	char **token;
	int i = 0, val = 0;

	val = strlen(buff);
	token = malloc(sizeof(char *) * val);
	if (token == NULL)
		return (NULL);
	word = strtok(buff, sep);
	while (word != NULL)
	{
		token[i] = word;
		i++;
		word = strtok(NULL, sep);
	}
	token[i] = NULL;
	return token;
}
/**
* add_dnodeint - adds a new node at the beginning of a list
* @head : head
* @n : number
* Return: new node
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	temp = *head;
	new->n = n;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		new->prev = NULL;
		temp->prev = new;
		*head = new;
	}
	return (*head);
}
/**
 * print_dlistint - function that prints all the elements of a list
 * @h : head
 * Return: number of elements
 */

size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
int main(int ac, char **av)
{
	char *buff;
	char **token, **word_cmp;
	int i = 0, j = 0, val = 0;
	stack_t *head;
	size_t n = 0;

	instruction_t fun[] = {{"push", add_dnodeint}, {"pall", print_dlistint}, {NULL, NULL}};
	head = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(1);
	}
	buff = read_textfile(av[1]);
	printf("%s\n", buff);
	token = tokens(buff, "\n");
	while (token[i] != NULL)
	{
		word_cmp = tokens(token[i], " ");
		while (fun[j].opcode != NULL)
		{
			val = strcmp(word_cmp[0], fun[j].opcode);
			if (val == 0)
			{
				(fun[j].f)(&head, atoi(word_cmp[1]));
				break;
			}
			j++;
		}
		i++;
	}
	n = print_dlistint(head);
	printf("%lu elements\n", n);
	return (0);
}
