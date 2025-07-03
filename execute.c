#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve.
 * @args: Argument array.
 * @program_name: Name of the shell program.
 */
void execute_command(char **args, char *program_name)
{
	pid_t pid;
	char *path = NULL;
	struct stat st;

	if (stat(args[0], &st) == 0)
		path = args[0];
	else
		path = getenv_path(args[0]);

	if (!path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(path, args, environ);
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		wait(NULL);
}


/**
 * getenv_path - Finds the full path of a command in PATH.
 * @command: Command name.
 *
 * Return: Full path or NULL.
 */
char *getenv_path(char *command)
{
	char *path = getenv("PATH");
	char *dir = NULL;
	char *full_path = NULL;
	struct stat st;

	if (!path)
		return (NULL);

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
			return (NULL);
		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
			return (full_path);

		free(full_path);
		dir = strtok(NULL, ":");
	}

	return (NULL);
}
