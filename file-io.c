#include "monty.h"

/**
 * read_monty - reads a text file and prints it to the POSIX stdout
 * @filename: the file
 *
 * Return: actual number of letters it could read and print
 */
char *read_monty(const char *filename)
{
	int fd, readretval;
	unsigned int charcount;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);

	buffer = _calloc(BUFSIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);

	charcount = 0;
	while (TRUE)
	{
		readretval = read(fd, (buffer + charcount), BUFSIZE);
		charcount += readretval;
		if (readretval == 0 && charcount == 0)
		{
			/* add error message */
			free(buffer);
			return (NULL);
		}
		else if (readretval == -1)
		{
			/* add error message */
		}
		else if (readretval != BUFSIZE)
			break;
		else
			buffer = _realloc(buffer, charcount, (charcount + BUFSIZE));
	}
	close(fd);

	return (buffer);
}

/**
 * parse_input - parses input string from bytecode .m file
 * @buffer: buffer string
 *
 * Return: head of linked list of input commands
 */
inputs_t *parse_input(char *buffer)
{
	(void)buffer;
	return (NULL);
}
