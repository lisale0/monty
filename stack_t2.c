#include "monty.h"

/**
 * _add - add two numbers from the top of that stack
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

/*	int numlen;
	char *num_str; */

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors("can't add");

	sum = (*stack)->n + (*stack)->next->n;
/*	numlen = num_len(sum);
	num_str = malloc(numlen * sizeof(char));

	if (num_str == NULL)
	handle_errors("malloc fail"); */

	_pop(stack, line_number);
	(*stack)->n = sum;
/*	_pop(stack, line_number);
	itos(num_str, sum);
	inventory->input[1] = num_str;
	_push(stack, line_number);
	free(num_str); */
}

/**
 * _nop - does not print, do not pass go, do not collect $200
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtracts the top element of the stack from the second top
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors("can't sub");

	difference = (*stack)->next->n - (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = difference;
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors("can't div");

	if ((*stack)->n == 0)
		handle_errors("div by 0");

	quotient = (*stack)->next->n / (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = quotient;
}

/**
 * _mul - multiplies the second top element of the stack with the top
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors("can't mul");

	product = (*stack)->next->n * (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = product;
}