#include "monty.h"

/**
 * build_inventory - builds global struct of most used variables
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int build_inventory()
{
	inventory = malloc(sizeof(inventory_t));
	inventory->input = malloc(sizeof(char *) * 3);
	inventory->stack = NULL;

	if (!inventory || !inventory->input)
		handle_errors("malloc fail");

	inventory->linenum = 0;
	inventory->line = NULL;

	return (EXIT_SUCCESS);
}
