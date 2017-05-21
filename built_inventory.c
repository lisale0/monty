#include "monty.h"

int allocate_inventory()
{
	return (EXIT_SUCCESS);
}

int build_inventory()
{
	inventory = malloc(sizeof(inventory_t));
	if (inventory == NULL)
		return (EXIT_FAILURE);
	inventory->instruct = malloc(sizeof(instruction_t) * 3);
	inventory->instruct[0].opcode =  "push";
	/*
	inventory->instruct = {
                {"push", _push},
                {"pall", _pall},
                {NULL, NULL}
        };
	*/
	return (EXIT_SUCCESS);
}
