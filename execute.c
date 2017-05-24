# include "monty.h"

/**
 * match_opcode - function to handle opcodes and their paired functions
 *
 * Return: function needed
 */

void (*match_opcode(void))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *input_opcode, *opcode;
	instruction_t instructions[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	input_opcode = inventory->input[0];
	if (input_opcode[0] == '#')
		return (_nop);
	while ((opcode = instructions[i].opcode))
	{
		if (strncmp(opcode, input_opcode, strlen(input_opcode)))
			i++;
		else
			return (instructions[i].f);
	}
	return (NULL);
}

/**
 * parse_line - parses line/getline into input global variable
 * @line: input line
 *
 * Return: void
 */

int parse_line(char *line)
{
	char *delim = " \t\n\r";

	inventory->input[0] = strtok(line, delim);
	inventory->input[1] = strtok(NULL, delim);
	return (EXIT_SUCCESS);
}
