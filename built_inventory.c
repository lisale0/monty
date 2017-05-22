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
	inventory->stack = malloc(sizeof(stack_t));

	if (!inventory || !inventory->input || !inventory->stack)
		handle_errors("malloc fail");

	inventory->linenum = 0;
	inventory->line = NULL;

	return (EXIT_SUCCESS);
}
