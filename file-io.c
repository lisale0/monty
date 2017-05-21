#include "monty.h"

/**
 * read_monty - reads a text file and prints it to the POSIX stdout
 * @filename: the file
 *
 * Return: actual number of letters it could read and print
 */
char *read_monty(const char *filename)
{
	int fd;
	unsigned int readretval, charcount, iterations;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);

	buffer = _calloc(BUFSIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);

	charcount = 0;
	iterations = 1;
	while (TRUE)
	{
		readretval = read(fd, (buffer + charcount), BUFSIZE);
		charcount += readretval;

		if (readretval <= 0 || readretval % BUFSIZE != 0)
			break;

		iterations++;
		buffer = _realloc(buffer, charcount, (BUFSIZE * iterations));
	}
	if (readretval == -1)
	{
		free(buffer);
		return (NULL);
	}
	close(fd);

	return (buffer);
}
