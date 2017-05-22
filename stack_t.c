# include "monty.h"

/**
 * are_digits - checks if every char in a string is a digit
 * @num: number to check if all chars are digits
 *
 * Return: TRUE or FALSE
 */
int are_digits(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
		if (isdigit(num[i]) == FALSE)
			return (FALSE);

	return (TRUE);
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
		handle_errors("push integer");
	else
		num = inventory->input[1];

	if (are_digits(num) == TRUE)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
			handle_errors("malloc fail");
	}
	else
		handle_errors("push integer");

	if (new_node)
	{
		new_node->n = atoi(num);
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
		handle_errors("pop empty");
	if ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		next->prev = NULL;
		free(*stack);
		*stack = next;
	}
	else
	{
		if (*stack != NULL)
		{
			free(*stack);
			*stack = NULL;
		}

	}
}
/*
void _pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
*/
