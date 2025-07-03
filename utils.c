#include "shell.h"

/**
 * free_args - Frees an array of strings.
 * @args: Array to free.
 */
void free_args(char **args)
{
	int i = 0;

	if (!args)
		return;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/**
 * trim_spaces - Removes leading and trailing spaces from input.
 * @str: The input string.
 *
 * Return: Pointer to trimmed string (same buffer).
 */
char *trim_spaces(char *str)
{
	char *end;

	while (*str == ' ')
		str++;

	if (*str == 0)
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && *end == ' ')
		end--;

	*(end + 1) = '\0';
	return (str);
}
