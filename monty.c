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
	char *line = NULL, *filename;
	size_t n;
	int  retval = 1;
	FILE *file;
	void (*execute)(stack_t **stack, unsigned int line_number);

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
	build_inventory();
	while ((retval = getline(&line, &n, file)) != -1)
	{
		parse_line(line);
		/*
		 * removing increment here because pall would increment this and
		 * and we do not want that
		inventory->linenum++;
		*/
		execute = match_opcode();
		execute(inventory->stack, inventory->linenum);
		/* 3. check flag for failure, if a function ptr fails, if fails
		 * break out of the while loop
		 */
	}
	return (EXIT_SUCCESS);
}
