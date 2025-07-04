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
 * exit_shell - Frees memory and exits the shell.
 * @args: Argument array to free.
 * @input: Input buffer to free.
 */
void exit_shell(char **args, char *input)
{
	free_args(args);
	free(input);
	exit(0);
}
