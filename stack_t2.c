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

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;

}
