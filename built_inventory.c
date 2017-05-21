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
	if (inventory == NULL)
		return (EXIT_FAILURE);
	/*inventory->instruct = malloc(sizeof(instruction_t));*/
	inventory->instruct = opcodes;
	/*
	inventory->instruct = {
                {"push", _push},
                {"pall", _pall},
                {NULL, NULL}
        };
	*/
	return (EXIT_SUCCESS);
}
