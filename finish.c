#include "monty.h"

/**
 * free_stack - frees all malloc'd in stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *temp;
	stack_t *head = *(inventory->stack);

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * free_all - frees all malloc'd memory
 *
 * Return: void
 */
void free_all(void)
{
	if (inventory)
	{
		free(inventory->line);
		free_stack();
	}
}

/**
 * find_error - finds error message
 * @error: the error message
 *
 * Return: int of error message
 */
int find_error(char *error)
{
	char *errors[] = {
		"malloc fail", "usage file", "can't open file", "push integer",
		"pop empty", "unknown instruction", NULL
	};
	int e = 0;

	while (errors[e] != NULL)
		if (strcmp(error, errors[e]) != 0)
			e++;
		else
			break;
	return (e);
}

/**
 * handle_errors - function to handle all errors
 *
 * Return: void
 */
void handle_errors(char *error)
{
	int e;
	unsigned int n;

	e = find_error(error);
	if (inventory)
		n = inventory->linenum;

	if (e == 0)
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
	else if (e == 1)
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
	else if (e == 2)
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
				inventory->filename);
	else if (e == 3)
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", n);
	else if (e == 4)
		dprintf(STDERR_FILENO,"L%u: can't pop an empty stack\n", n);
	else if (e == 5)
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", n,
				inventory->input[0]);

	free_all();
	exit(EXIT_FAILURE);
}
