#include "monty.h"

/**
 * freemem - frees generated tokens
 * @tokens: pointer to heap mem
 * @front: pointer to @tokens
 * Return: 0 on success, 1 on error
 */
int freemem(char **tokens, char **front)
{
	int index = 0;

	for (; tokens[index]; index++)
	{
		free(tokens[index]);
	}
	free(front);
	return (0);
}
