#include "monty.h"
char **tokens;
stack_t *head = NULL;
char *topcode = NULL;
char *num = NULL;
char *buff = NULL;
/**
 * main - main function
 * @argc: argument count.
 * @argv: pointer to argument variables.
 * Return: 0 if successful.
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	int exit_status = 0;

	if (argc != 2)
		exit(inc_error());
	
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(file_error(argv[1]));
	exit_status = handle_monty(fp);
	frees_stack();
	fclose(fp);
	return (exit_status);
}
