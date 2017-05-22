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
	FILE *file;
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_number);

	inventory = NULL;
	if (argc != 2)
		handle_errors("usage file");

	build_inventory();
	inventory->filename = argv[1];

	file = fopen(inventory->filename, "r");
	if (file == NULL)
		handle_errors("can't open file");

	while (getline(&inventory->line, &n, file) > 0)
	{
		parse_line(inventory->line);
		inventory->linenum++;
		execute = match_opcode();
		if (execute == NULL)
			handle_errors("unknown instruction");

		execute(&inventory->stack, inventory->linenum);
	}
	fclose(file);
	free_all();
	return (EXIT_SUCCESS);
}
