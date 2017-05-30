#include "monty.h"

/**
 * _stack - switches to stack to LIFO
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	inventory->order = LIFO;
}

/**
 * _queue - switches to queue FIFO
 * @stack: the stack
 * @line_number: line number
 *
 * Return: None
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	inventory->order = FIFO;
}
