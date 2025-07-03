#include "shell.h"

/**
 * handle_builtins - Handles built-in commands like exit and env.
 * @args: Argument array.
 * @input: Input string to free on exit.
 *
 * Return: 1 if a built-in was executed, 0 otherwise.
 */
int handle_builtins(char **args, char *input)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		free(input);
		exit(0);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		free_args(args);
		return (1);
	}

	return (0);
}
