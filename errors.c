#include "monty.h"

/**
 * inc_error - handles incomplete/too much argument error.
 * return: EXIT_FAILURE
 */
int inc_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_error - handles file (not opening) error.
 * str: file name
 * return: EXIT_FAILURE
 */
int file_error(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	return (EXIT_FAILURE);
}

/**
 * instruction_error - hanldles unknown opcode error
 * @line_n: line number
 * @opcode: unknown opcode
 * return: returns EXIT_FAILURE
 */
int instruction_error(unsigned int line_n, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - handles malloc error
 * return: returns EXIT_FAILURE
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	freemem(tokens, tokens);
	frees_stack();
	free(buff);
	 exit(EXIT_FAILURE);
}
