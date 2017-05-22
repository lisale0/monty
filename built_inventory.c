#include "monty.h"

int allocate_inventory()
{
	return (EXIT_SUCCESS);
}

int build_inventory()
{
	inventory = malloc(sizeof(inventory_t));
	inventory->input = malloc(sizeof(char *) * 3);
	if (inventory == NULL || inventory->input == NULL)
		return (EXIT_FAILURE);
        inventory->linenum = 0;

	return (EXIT_SUCCESS);
}
