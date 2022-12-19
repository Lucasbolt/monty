#include "monty.h"

/**
 * pint - Prints the value at the top of the stack,
 * followed by a new line.
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 *
 * Return: Nothing
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		pint_error(line_number);

	printf("%d\n", (*stack)->n);
}
