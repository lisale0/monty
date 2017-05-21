# include "monty.h"

/**
 * execute_opcode - function to handle opcodes and their paired functions
 * @opcode: string input (char *) of opcode from .m file
 *
 * Return: function needed
 */
void (*execute_opcode(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (_strncmp(opcodes[i].opcode, s, _strlen(s)))
			i++;
		else
			return (opcodes[i].f);
	}

	return (NULL);
}
