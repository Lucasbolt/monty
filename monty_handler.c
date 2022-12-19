#include "monty.h"
/**
 * token_count - counts number of tokens
 * @tk: pointer to tokens array
 * return: number of tokens
 */
int token_count(char **tk)
{
	int index = 0;
	for (; tk[index] != NULL;)
		index++;
	return (index);
}
/**
 * handle_opcode -handles opcodes
 * @stack: stack pointer
 * @string: opcode
 * @line_n: line number
 * return: EXIT_SUCCESS or EXIT_FAILURE on failure
 */
int handle_opcode(char *string, unsigned int line_n)
{
	int index, status = 0;
	instruction_t handlers[] = {

								{"push", handle_push},
								{PALL, handle_pall},
								{PINT, handle_pint},
								{POP, handle_pop},
								{"swap", handle_swap},
								{"add", handle_add},
								{NOP, handle_nop},
								{"zero", NULL}
								};
	for (index = 0; handlers[index].f; index++)
	{
		if (strcmp(handlers[index].opcode, string) == 0)
		{
			if (strcmp("push", string) == 0)
			{
				status = check_push_param(num);
				if (status == 201)
					push_error(line_n);
				handlers[index].f(&head, line_n);
				freemem(tokens, tokens);
				return (EXIT_SUCCESS);
			}
			handlers[index].f(&head, line_n);
			freemem(tokens, tokens);
			return (EXIT_SUCCESS);
		}

	}
	return(instruction_error(line_n, string));
}
/**
 * handle_monty - handles monty files
 * @fp: file descriptor
 * return: EXIT_SUCCESS on success, else, returns EXIT_FAILURE
 */
int handle_monty(FILE *fp)
{
	size_t len = 0;
	ssize_t read;
	unsigned int line_n = 1;
	char *mline;
	int status = EXIT_SUCCESS;

	while ((read = getline(&buff, &len, fp)) != -1)
	{
		mline = modifier(buff);
		if (strlen(mline) > 1)
		{
			tokens = string_splitter(mline);
			topcode = tokens[0];
			if (token_count(tokens) >= 2)
			{
				num = tokens[1];
			}
			status = handle_opcode(topcode, line_n++);
			if (status != EXIT_SUCCESS)
			{
				free(buff);
				free(mline);
				frees_stack();
				freemem(tokens, tokens);
				return (status);
			}
		}
		free(mline);

	}
	if (buff)
		free(buff);
	return (EXIT_SUCCESS);
}
