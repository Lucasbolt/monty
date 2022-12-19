#include "monty.h"
/**
  * check_push_param - Check the parameter of the push instruction
  * @param: The parameter to be verified
  *
  * Return: 0 if is a valid param or errcode if is invalid
  */
int check_push_param(char *param)
{
	if (param == NULL)
		return (201);

	return (0);
}

/**
  * check_digits - Checks if all characters in a string are digits
  * @s: The string to be evaluated
  *
  * Return: 1 if all if all evaluated characters are digits or 0 if not
  */
int check_digits(char *s)
{
	int status = 1;

	while (*s != '\0')
	{
		if (s[0] == 45)
		{
			++s;
			continue;
		}

		if (isdigit(*s) == 0)
		{
			status = 0;
			return (status);
		}

		++s;
	}

	return (status);
}
