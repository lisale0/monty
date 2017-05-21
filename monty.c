#include "monty.h"

/**
 * main - main function for monty program
 * @argc: arguments count
 * @argv: arguments inventory (file path expected)
 *
 * Return: 0 always - success!
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char *filename;
	size_t n;
	int  retval = 1;
	FILE *file;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while ((retval = getline(&line, &n, file)) != -1)
	{
		printf("%s", line);
	}
	return (EXIT_SUCCESS);
}
