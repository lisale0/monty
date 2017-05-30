# include "monty.h"

/**
 * add_node_lifo - adds a new node at the beginning of a stack_t list
 * @stack: head of stack (linked list)
 * @new_node: the node to add
 *
 * Return: void
 */
void add_node_lifo(stack_t **stack, stack_t *new_node)
{
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * add_node_fifo - adds a new node at the end of a stack_t list
 * @stack: head of stack (linked list)
 * @new_node: the node to add
 *
 * Return: void
 */
void add_node_fifo(stack_t **stack, stack_t *new_node)
{
	stack_t *copy = *stack;

	new_node->next = NULL;
	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		while (copy->next)
			copy = copy->next;
		copy->next = new_node;
		new_node->prev = copy;
	}
}

/**
 * _push - adds a new node at the beginning of a stack_t list
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *num;
	(void)line_number;

	if (inventory->input[1] == NULL)
		handle_errors(ERROR_PUSH);
	else
		num = inventory->input[1];
	if (are_digits(num) == TRUE)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
			handle_errors(ERROR_MALLOC);
	}
	else
		handle_errors(ERROR_PUSH);

	new_node->n = atoi(num);
	if (inventory->order == LIFO)
		add_node_lifo(stack, new_node);
	else
		add_node_fifo(stack, new_node);
}
