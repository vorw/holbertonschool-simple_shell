#include "main.h"

/**
 * simple_shell - basic UNIX command line interpreter
 */
void simple_shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			char *argv[] = {line, NULL};

			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
}
