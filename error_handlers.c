#include "monty.h"
/**
 * push_error - handles push error
 * @line_n: line number
 */
void push_error(unsigned int line_n)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_n);
	free(buff);
	if (count_stack(head) > 0)
		freemem(tokens, tokens);
	frees_stack();
	exit(EXIT_FAILURE);
}
/**
 * pint_error - handles pint error
 * @line_n: line number
 */
void pint_error(unsigned int line_n)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_n);
	free(buff);
	freemem(tokens, tokens);
	frees_stack();
	exit(EXIT_FAILURE);
}

/**
 * pop_error - handles pop error
 * @line_n: line number
 */
void pop_error(unsigned int line_n)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_n);
	free(buff);
	freemem(tokens, tokens);
	frees_stack();
	exit(EXIT_FAILURE);
}
/**
 * swap_error - handles pop error
 * @line_n: line number
 */

void swap_error(unsigned int line_n)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_n);
	free(buff);
	freemem(tokens, tokens);
	frees_stack();
	exit(EXIT_FAILURE);

}
/**
 * add_error - handles pop error
 * @line_n: line number
 */

void add_error(unsigned int line_n)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_n);
	free(buff);
	freemem(tokens, tokens);
	frees_stack();
	exit(EXIT_FAILURE);

}
