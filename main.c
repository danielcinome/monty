#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

int main(int ac, char **av)
{
	char *buff;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(1);
	}
	buff = read_textfile(av[1]);
	printf("%s\n", buff);
	return (0);
}