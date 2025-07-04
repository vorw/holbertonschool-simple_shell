#include "shell.h"

/**
 * main - Entry point of the shell.
 * @ac: Argument count (unused)
 * @av: Argument vector (used for program name)
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *input = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t nread;
	int interactive = isatty(STDIN_FILENO);
	int last_status = 0;

	(void)ac;

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&input, &len, stdin);
		if (nread == -1)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (input[nread - 1] == '\n')
			input[nread - 1] = '\0';

		args = tokenize(input);
		if (!args || !args[0])
		{
			free_args(args);
			continue;
		}

		if (handle_builtin(args, input, last_status))
		{
			free_args(args);
			continue;
		}

		execute_command(args, av[0], &last_status);
		free_args(args);
	}

	free(input);
	return (0);
}
