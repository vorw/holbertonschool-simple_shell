#include "shell.h"

/**
 * handle_builtin - Handles built-in commands like exit and env.
 * @args: Argument array.
 * @input: Input string to free on exit.
 * @last_status: Last exit status to use with exit.
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int handle_builtin(char **args, char *input, int last_status)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		free(input);
		exit(last_status);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return (1);
	}

	return (0);
}
