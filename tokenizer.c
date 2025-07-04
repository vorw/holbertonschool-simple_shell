#include "simple_shell.h"

/**
 * split_line - Breaks a string into tokens by space.
 * @line: Input string.
 *
 * Return: Array of tokens.
 */
char **split_line(char *line)
{
	char **tokens = NULL;
	char *tok = NULL;
	int idx = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);

	tok = strtok(line, " ");
	while (tok)
	{
		tokens[idx++] = strdup(tok);
		tok = strtok(NULL, " ");
	}
	tokens[idx] = NULL;

	return (tokens);
}
