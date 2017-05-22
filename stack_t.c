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
	        printf("%d\n", copy->n);
	}
}


void _pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *next;

	if ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	else
	{
		*stack = NULL;
		free(*stack);
	}
}
/*
void _pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
*/
