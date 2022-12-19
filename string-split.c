#include "monty.h"

/**
 * delim_count - counts number of words in a string
 * @command: strings to check
 * Return: number of words
 */
int delim_count(char *command)
{
	int words = 0, index;

	if (command == NULL || command[0] == '\0')
		return (-1);

	for (index = 0; command[index]; index++)
	{
		if (command[index] == ' ' && (command[index + 1] != ' '
			&& command[index + 1] != '\0'))
			words++;
		/*index++;*/
	}
	words++;

	return (words);
}
/**
 * string_splitter - splits strings into substings
 * @command: the string to split
 * Return: return a pointer array of substrings
 */
char **string_splitter(char *string)
{
	int wcount, index = 0, index1 = 0, num = 0;
	char **tokens;
	wcount = delim_count(string);
	if (wcount < 1)
		return (NULL);
	tokens = malloc(sizeof(char *) * (wcount + 2));
	if (tokens == NULL)
		return (NULL);
	tokens[num] = malloc(sizeof(char) * strlen(string) + 1);

	while (string[index])
	{
		if (string[index] == ' ' || string[index] == '\n')
		{
			tokens[num][index1] = '\0';
			num++;
			tokens[num] = malloc(sizeof(char) * strlen(string) + 1);
			index++;
			index1 = 0;
		}
		tokens[num][index1] = string[index];
		index++;
		index1++;
	}
	tokens[num + 1] = NULL;
	tokens[num][index1] = '\0';
	return (tokens);
}
