#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void handle_swap(stack_t **stack, unsigned int line_number)
{
	unsigned int length = 0, temp = 0;

	length = count_stack(*stack);

	if (length < 2)
		swap_error(line_number);

	if (*stack)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
