#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point
 * Description: simple shell
 * Return: 0
 */

extern char **environ;

int main(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t characters;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		characters = getline(&line, &size, stdin);
		if (characters == -1)
		{
			printf("\n");
			break;
		}
		if (line[characters - 1] == '\n')
			line[characters - 1] = '\0';
		pid = fork();

		if (pid == 0)
		{
			char *args[2];
			args[0] = line;
			args[1] = NULL;

			if (execve(line, args, environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	return (0);
}
