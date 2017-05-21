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
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");
        if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s", filename);
		return (EXIT_FAILURE);
	}
	while ((retval = getline(&line, &n, file)) != -1)
	{
		printf("%s", line);
	}

/**
 * (1) call read file function to read monty bytecode file
 *     -handle errors for no file, etc...
 * (2) add codes to a new stack that we need to create
 *     -handle errors for unknown codes, etc...
 * (3) sort through new stack of codes, and use the execute function to
 *     -handle errors for improper argument or no args for the given opcode
 * (4) call and execute each code one at a time while sorting through list
 * (5) after reading all input codes, terminate successfully
 */
	return (EXIT_SUCCESS);
}
