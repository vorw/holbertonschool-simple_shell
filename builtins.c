#include "simple_shell.h"

/**
 * process_builtin - Handles 'exit' and 'env' built-ins.
 * @tokens: Input tokens.
 * @line: Line to free on exit.
 * @status: Last exit status to use.
 *
 * Return: 1 if handled, 0 otherwise.
 */
int process_builtin(char **tokens, char *line, int status)
{
	int i;

	if (strcmp(tokens[0], "exit") == 0)
	{
		free_tokens(tokens);
		free(line);
		exit(status);
	}

	if (strcmp(tokens[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		free_tokens(tokens);
		return (1);
	}

	return (0);
}
