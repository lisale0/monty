# include "monty.h"

/**
 * _push - adds a new node at the beginning of a stack_t list
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 * Return: void
 */
void _push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *new_node;
	int num;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if ( new_node == NULL)
		return;
	num = atoi(inventory->input[1]);
	if (num == 0)
		return;
	if (new_node != NULL)
	{
		new_node->n = num;
		new_node->prev = NULL;
		new_node->next = *stack;
		*stack = new_node;
	}
	inventory->linenum += 1;
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
	stack_t *copy = *stack;
	size_t i;
	(void)line_number;

	for (i = 0; copy; i++, copy = copy->next)
	{
		if (copy != NULL)
			printf("%d\n", copy->n);
	}
}

/**
 * _pop - pop the top element off the stack, i.e. remove head
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 */
void _pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *next;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO,"L%d: can't pop an empty stack\n",
			inventory->linenum);
		return;
	}
	if ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		next->prev = NULL;
		free(*stack);
		*stack = next;
		inventory->linenum -= 1;
	}
	else
	{
		if (*stack != NULL)
		{
			free(*stack);
			*stack = NULL;
			inventory->linenum -= 1;
		}

	}

}
/*
void _pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
*/
