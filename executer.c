#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve.
 * @args: Argument array.
 * @program_name: Name of the shell program.
 */
void execute_command(char **args, char *program_name)
{
	pid_t pid;
	char *full_path = NULL;
	struct stat st;

	if (stat(args[0], &st) == 0)
		full_path = args[0];
	else
		full_path = getenv_path(args[0]);

	if (!full_path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		exit(127);
	}

	pid = fork();
	if (pid == 0)
	{
		execve(full_path, args, environ);
		perror(program_name);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		wait(NULL);

	if (full_path != args[0])
		free(full_path);
}

/**
 * getenv_path - Finds the full path of a command in PATH.
 * @command: Command name.
 *
 * Return: Full path or NULL.
 */
char *getenv_path(char *command)
{
	char *path_env = NULL, *path_copy = NULL, *dir = NULL, *full_path = NULL;
	struct stat st;
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
		i++;
	}

	if (!path_env || path_env[0] == '\0')
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
