#include "monty.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of file
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
