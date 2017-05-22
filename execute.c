# include "monty.h"

/**
 * execute_opcode - function to handle opcodes and their paired functions
 * @opcode: string input (char *) of opcode from .m file
 *
 * Return: function needed
 */
/*
void (*execute_opcode(void))(stack_t **stack, unsigned int line_number)
*/
void execute_opcode()
{
	int i = 0;
	char *input_opcode;

	instruction_t opcodes[] = {
                {"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{NULL, NULL}
        };

	input_opcode = inventory->input[0];
	printf("This is the first one %s\n", opcodes[0].opcode);
	while (opcodes[i].opcode)
	{
		if (strncmp(opcodes[i].opcode, input_opcode,
			    strlen(input_opcode)))
			i++;
		else
		{
			printf("found %s\n", opcodes[i].opcode);
			opcodes[i].f(inventory->stack, inventory->linenum);
			break;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s",
		inventory->linenum, input_opcode);
}

/**
 *
 * parses line/getline into input global variable
 *
 *
 */

int parse_line(char *line)
{
	char *delim = " \t\n\r";
	inventory->input[0] = strtok(line, delim);
	inventory->input[1] = strtok(NULL, delim);
	return (EXIT_SUCCESS);
}
