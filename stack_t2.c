#include "monty.h"

/**
 * _swap - swap the top two elements
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;

	if((*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			inventory->linenum);
		return;
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * _add - add two numbers from the top of that stack
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum, numlen;
	char *num_str;

	sum = (*stack)->n + (*stack)->next->n;
	numlen = num_len(sum);
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return;
	_pop(stack, line_number);
	_pop(stack, line_number);
	itos(num_str, sum);
	inventory->input[1] = num_str;
	_push(stack, line_number);
	free(num_str);
}
