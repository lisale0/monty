#include "monty.h"

int allocate_inventory()
{
	return (EXIT_SUCCESS);
}

int build_inventory()
{
	instruction_t opcodes[] = {
                {"push", _push},
                {"pall", _pall},
                {NULL, NULL}
        };
	inventory = malloc(sizeof(inventory_t));
	inventory->input = malloc(sizeof(char *) * 3);
	if (inventory == NULL || inventory->input == NULL)
		return (EXIT_FAILURE);
        inventory->linenum = 0;
	/*
	inventory->instruct = malloc(sizeof(instruction_t) * 3);
	inventory->instruct = opcodes;
	*/
	return (EXIT_SUCCESS);
}
