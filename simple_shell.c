#include "main.h"

/**
 * simple_shell - runs a simple shell loop
 */
void simple_shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;

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

		/* Remove newline */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		pid = fork();
		if (pid == 0)
		{
			char *argv[] = {line, NULL};

			if (execve(argv[0], argv, environ) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);
	}
}
