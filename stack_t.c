# include "monty.h"

/**
 * _push - adds a new node at the beginning of a stack_t list
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * _pall - prints all the elements from the stack
 * @stack: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = stack;
	size_t i;
	(void)line_number

	for (i = 0; copy; i++, copy = copy->next)
	{
		write_uint(copy->n);
		putchar('\n');
	}
}
