#include "shell.h"

/**
 * handle_exit_env - Handles built-in commands: exit and env
 * @args: Array of command and its arguments
 * @line: The input line (to free if exiting)
 * @status: Pointer to status variable to exit with
 *
 * Return: 1 if built-in command was handled, 0 otherwise
 */
int handle_exit_env(char **args, char *line, int *status)
{
	int i = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		exit(*status);
	}

	if (strcmp(args[0], "env") == 0)
	{
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (1);
	}

	return (0);
}
