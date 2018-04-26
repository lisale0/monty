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
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_number);

	inventory = NULL;
	if (argc != 2)
		handle_errors(ERROR_USAGE_FILE);
	/*Builds the global struct of most used variables*/
	build_inventory();
	/*Get file name*/
	inventory->filename = argv[1];
	/*Open file*/
	inventory->file = fopen(inventory->filename, "r");
	if (inventory->file == NULL)
		handle_errors(ERROR_OPEN_FILE);
	/*Read each line or opscode in the file*/
	while (getline(&inventory->line, &n, inventory->file) > 0)
	{
		inventory->linenum++;
		/*Parse the line, if it fails, go to the next time in the file*/
		if (parse_line(inventory->line) == EXIT_FAILURE)
			continue;
		/*Find the right instruction*/
		execute = match_opcode();
		execute(&inventory->stack, inventory->linenum);
	}
	free_all();
	return (EXIT_SUCCESS);
}
