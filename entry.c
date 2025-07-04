#include "simple_shell.h"

/**
 * main - Entry point of the shell.
 * @argc: Argument count (unused)
 * @argv: Argument vector (used for program name)
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **tokens = NULL;
	size_t len = 0;
	ssize_t chars_read;
	int is_terminal = isatty(STDIN_FILENO);
	int status = 0;

	(void)argc;

	while (1)
	{
		if (is_terminal)
			write(STDOUT_FILENO, "($) ", 4);

		chars_read = getline(&line, &len, stdin);
		if (chars_read == -1)
			break;

		if (line[chars_read - 1] == '\n')
			line[chars_read - 1] = '\0';

		tokens = split_line(line);
		if (!tokens || !tokens[0])
		{
			free_tokens(tokens);
			continue;
		}

		if (process_builtin(tokens, line, status))
			continue;

		run_command(tokens, argv[0], &status);
		free_tokens(tokens);
	}

	free(line);
	return (status);
}
