#include "shell.h"

/**
 * execute_command - Run a command using fork and execve
 * @args: Array of command and its arguments
 *
 * Forks a child process to run the command.
 * The parent waits for the child to finish.
 * Return: Exit status of the executed command,
 *         127 if command not found,
 *         1 if fork or execve fails.
 */
int execute_command(char **args)
{
	pid_t pid;
	char *cmd_path;
	int status;

	if (args[0] == NULL)
		return (0);

	cmd_path = strchr(args[0], '/') ? args[0] : find_path(args[0]);

	if (cmd_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(cmd_path, args, environ) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
