#include "shell.h"

/**
 * tokenize - Splits a string into tokens.
 * @input: The input string.
 *
 * Return: Array of strings (tokens).
 */
char **tokenize(char *input)
{
	char **args = NULL;
	char *token = NULL;
	int i = 0;

	args = malloc(sizeof(char *) * 64);
	if (!args)
		return (NULL);

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i] = strdup(token);
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}
