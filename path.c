#include "shell.h"

/**
 * get_path_from_environ - Gets the value of PATH from environment variables
 *
 * Return: Pointer to the value after "PATH=", or NULL if not found
 */

char *get_path_from_environ(void)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * find_path - Looks for a command inside PATH directories
 * @command: The name of the command (e.g. "ls")
 *
 * Return: Full path of the command if found, or NULL if not found
 */

char *find_path(char *command)
{
	char *path = get_path_from_environ();
	static char full_path[1024];
	char *path_copy, *dir;

	if (path == NULL || *path == '\0')
		return (NULL);

	path_copy = strdup(path);

	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");

	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
