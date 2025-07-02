#include "shell.h"

/**
 * tokenize - Splits a line into words (tokens)
 * @line: The input string to split
 * @args: The array to store the tokens
 *
 * This function uses space as the delimiter.
 */
void tokenize(char *line, char **args)
{
	char *token;
	int i = 0;

	token = strtok(line, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
